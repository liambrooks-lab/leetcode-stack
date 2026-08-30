#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<char> numbers;
        
        // Pre-compute (n-1)! and fill our available numbers pool
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i + '0');
        }
        numbers.push_back(n + '0');
        
        string ans = "";
        k = k - 1; // 0-based indexing for accurate mathematical offsets
        
        // The Factorial Block Engine
        for (int i = n; i > 0; i--) {
            int idx = k / fact;
            ans += numbers[idx];
            
            // Remove the used character so it doesn't get picked again (O(N) operation, but N <= 9 so it's instantaneous)
            numbers.erase(numbers.begin() + idx);
            
            // Re-adjust k and the factorial block size for the next iteration
            if (i > 1) {
                k = k % fact;
                fact = fact / (i - 1);
            }
        }
        
        return ans;
    }
};