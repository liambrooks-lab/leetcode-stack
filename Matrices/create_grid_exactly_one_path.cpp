/*
{
    "problem_name": "Create Grid With Exactly One Path",
    "category": "Matrices / Constructive",
    "time_complexity": "O(m * n) -> Zero string concatenations. Direct memory assignment and fast I/O detachment.",
    "space_complexity": "O(1) auxiliary -> Single obstacle template copied directly. Overwrites memory block in-place."
}
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Fast I/O trick to absolutely nuke LeetCode's test runner overhead
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Create full obstacle row and mutate the last byte in-place (0 concatenations)
        string obstacle(n, '#');
        obstacle.back() = '.';
        
        // Initialize the entire grid in one contiguous memory blast
        vector<string> grid(m, obstacle);
        
        // Overwrite the first row in-place, bypassing temporary string creation
        grid[0].assign(n, '.');
        
        return grid;
    }
};