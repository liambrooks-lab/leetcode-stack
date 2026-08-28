from collections import Counter


class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = Counter(s)

        odds = [c for c, v in cnt.items() if v % 2]
        if len(odds) > n % 2:
            return ""

        mid = odds[0] if odds else ""
        h = n // 2

        pool = Counter({
            c: v // 2
            for c, v in cnt.items()
        })

        def build(half):
            return half + mid + half[::-1]

        stop = 0

        # Match as much of the target's left half as possible.
        while stop < h and pool[target[stop]] > 0:
            pool[target[stop]] -= 1
            stop += 1

        # The target's left half can be formed completely.
        if stop == h:
            candidate = build(target[:h])
            if candidate > target:
                return candidate

        # Move backwards and increase the last possible position.
        for i in range(stop, -1, -1):
            if i < h:
                bigger = min(
                    (
                        c
                        for c in pool
                        if c > target[i] and pool[c] > 0
                    ),
                    default=""
                )

                if bigger:
                    pool[bigger] -= 1

                    suffix = ""
                    for c in sorted(pool):
                        suffix += c * pool[c]

                    return build(
                        target[:i] + bigger + suffix
                    )

            # Restore the character used at the previous position.
            if i:
                pool[target[i - 1]] += 1

        return ""