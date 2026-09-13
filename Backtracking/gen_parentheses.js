/*
{
  "problem_name": "Gen Parentheses",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];

    backtrack = (open, close, current) => {
        if (close === n) {
            result.push(current);
            return;
        }

        if (open < n) {
            backtrack(open + 1, close, current + "(");
        }

        if (close < open) {
            backtrack(open, close + 1, current + ")");
        }
    }

    backtrack(0, 0, "");

    return result;
};
