/*
{
  "problem_name": "First Occurrence Str",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
const strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};