class Solution:
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])

        res = []
        append = res.append

        start, end = intervals[0]

        for i in range(1, len(intervals)):
            s, e = intervals[i]

            if s <= end:
                if e > end:
                    end = e
            else:
                append([start, end])
                start, end = s, e

        append([start, end])
        return res