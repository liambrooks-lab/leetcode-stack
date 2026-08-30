class Solution:
    def insert(self, intervals, newInterval):
        res = []
        start, end = newInterval
        i = 0
        n = len(intervals)

        while i < n and intervals[i][1] < start:
            res.append(intervals[i])
            i += 1

        while i < n and intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
            i += 1

        res.append([start, end])

        while i < n:
            res.append(intervals[i])
            i += 1

        return res