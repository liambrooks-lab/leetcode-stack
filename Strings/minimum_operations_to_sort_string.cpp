/*
{
    "problem": "Minimum Operations to Make String Sorted",
    "category": "Strings / Greedy",
    "time_complexity": "O(N) -> Pure linear scans using STL is_sorted and bare-metal loops. No nested overheads.",
    "space_complexity": "O(1) -> Strict constant space, purely tracking min/max chars and state flags."
}
*/
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(const string &s) {
        // O(N) pass to check if it's already sorted
        bool isSorted = is_sorted(s.begin(), s.end());

        if (isSorted) {
            return 0;
        }

        const int n = static_cast<int>(s.size());
    
        // If length is 2 and it's not sorted, we can't sort a proper substring
        if (n == 2) {
            return -1;
        }

        // Find absolute min and max characters in O(N)
        char minVal = s[0], maxVal = s[0];
        for (char ch : s) {
            minVal = min(minVal, ch);
            maxVal = max(maxVal, ch);
        }

        // 1-Op Condition: Min is at the start OR Max is at the end
        if (s[0] == minVal || s[n - 1] == maxVal) {
            return 1;
        }

        // 2-Op Condition: If minVal or maxVal is anywhere in the middle
        for (int i = 1; i + 1 < n; ++i) {
            if (s[i] == minVal || s[i] == maxVal) {
                return 2;
            }
        }

        // 3-Op Condition: Deadlock where Max is strictly at start and Min strictly at end
        return 3;
    }
};