class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        freq = [0] * 26
        for char in s:
            freq[ord(char) - 97] += 1
            
        # O(N) Prefix tracking without creating sub-arrays
        matched = []
        for i in range(len(target)):
            idx = ord(target[i]) - 97
            if freq[idx] > 0:
                freq[idx] -= 1
                matched.append(idx)
            else:
                break
                
        start_i = len(matched)
        
        # If target is perfectly matched, we must diverge at the last character
        if start_i == len(target):
            start_i -= 1
            freq[matched.pop()] += 1
            
        # The Dynamic Rollback Protocol
        for i in range(start_i, -1, -1):
            target_char_idx = ord(target[i]) - 97
            
            # Find the strictly greater character
            for c in range(target_char_idx + 1, 26):
                if freq[c] > 0:
                    freq[c] -= 1
                    rem = []
                    
                    # Sort remaining tail
                    for k in range(26):
                        if freq[k] > 0:
                            rem.append(chr(k + 97) * freq[k])
                            
                    return target[:i] + chr(c + 97) + "".join(rem)
                    
            # Backtrack: Release the character matched at the previous index
            if i > 0:
                freq[matched[i-1]] += 1
                
        return ""