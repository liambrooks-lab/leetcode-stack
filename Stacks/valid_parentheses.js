/*
{
  "problem_name": "Valid Parentheses",
  "category": "Stacks",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var closeMapping = {
        "{": "}",
        "(": ")",
        "[": "]"
    };

    for (let i = 0; i < s.length; i++) {
        var c = s[i];
        if (c == "(" || c == "{" || c == "[") {
            stack.push(c);
            continue;
        }

        var open = stack.pop();
        
        if (open == undefined || closeMapping[open] != c) {
            return false;
        }
    }

    return stack.length == 0;
};