/*
{
    "problem_name": "Evaluate the Bracket Pairs of a String",
    "category": "String Manipulation / Hash Map",
    "time_complexity": "O(N + K)",
    "space_complexity": "O(N + K)"
}
*/

// Compiler level optimizations to force vectorization and bypass standard checks
#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Desync C++ streams from C streams for absolute raw I/O speed
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        
        //  Pre-allocate hash map memory to completely bypass expensive rehashing
        dict.reserve(knowledge.size());
        for (const auto& kv : knowledge) {
            dict[kv[0]] = kv[1];
        }
        
        string res;
        // Pre-allocate string memory to avoid dynamic resizing bottlenecks
        res.reserve(s.size());
        
        size_t i = 0;
        
        // Block-chunking architecture (No slow character-by-character loops)
        while (i < s.length()) {
            size_t start = s.find('(', i);
            
            if (start == string::npos) {
                // Block memory append for the remaining tail string
                res.append(s, i, string::npos);
                break;
            }
            
            // Append the exact chunk before the bracket in one raw memory operation
            res.append(s, i, start - i);
            
            size_t end = s.find(')', start + 1);
            string key = s.substr(start + 1, end - start - 1);
            
            // Single probe native hash lookup
            auto it = dict.find(key);
            if (it != dict.end()) {
                res.append(it->second);
            } else {
                res.push_back('?');
            }
            
            // Jump the pointer directly past the closing bracket
            i = end + 1;
        }
        
        return res;
    }
};