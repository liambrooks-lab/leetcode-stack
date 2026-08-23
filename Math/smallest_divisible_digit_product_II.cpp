/*
 * Problem: Smallest Divisible Digit Product II
 * Approach: Constructive Math / Greedy String Manipulation
 * Time Complexity: O(N) - Where N is the length of the string.
 * Space Complexity: O(N) - To store and manipulate the resulting numerical string.
 */

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        
        while(temp % 2 == 0) { req2++; temp /= 2; }
        while(temp % 3 == 0) { req3++; temp /= 3; }
        while(temp % 5 == 0) { req5++; temp /= 5; }
        while(temp % 7 == 0) { req7++; temp /= 7; }
        if(temp > 1) return "-1"; 
        
        int n = num.size();
        int cur2 = 0, cur3 = 0, cur5 = 0, cur7 = 0;
        int first_zero = -1;
        
        // Single pass prefix counting (No Extra Memory/Vectors!)
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && first_zero == -1) first_zero = i;
            int d = num[i] - '0';
            if (d > 0) {
                while(d % 2 == 0) { cur2++; d /= 2; }
                while(d % 3 == 0) { cur3++; d /= 3; }
                while(d % 5 == 0) { cur5++; d /= 5; }
                while(d % 7 == 0) { cur7++; d /= 7; }
            }
        }
        
        if (first_zero == -1 && cur2 >= req2 && cur3 >= req3 && cur5 >= req5 && cur7 >= req7) {
            return num;
        }

        // Raw Array for lightning-fast DP state (Zero Overhead)
        int dp[60][40];
        memset(dp, -1, sizeof(dp));
        auto get_min_d = [&](auto& self, int r2, int r3) -> int {
            r2 = max(0, r2); r3 = max(0, r3);
            if (r2 == 0 && r3 == 0) return 0;
            if (dp[r2][r3] != -1) return dp[r2][r3];
            
            int res = 1e9;
            if (r2 > 0) res = min(res, 1 + self(self, r2 - 3, r3));     
            if (r3 > 0) res = min(res, 1 + self(self, r2, r3 - 2));     
            if (r2 > 0 || r3 > 0) res = min(res, 1 + self(self, r2 - 1, r3 - 1)); 
            if (r2 > 0) res = min(res, 1 + self(self, r2 - 2, r3));     
            if (r3 > 0) res = min(res, 1 + self(self, r2, r3 - 1));     
            if (r2 > 0) res = min(res, 1 + self(self, r2 - 1, r3));     
            
            return dp[r2][r3] = res;
        };

        auto get_min_len = [&](int r2, int r3, int r5, int r7) {
            return max(0, r5) + max(0, r7) + get_min_d(get_min_d, r2, r3);
        };

        // Sliding Window Pivot Search
        for (int i = n - 1; i >= 0; --i) {
            // Remove current element from our rolling counts
            int d_orig = num[i] - '0';
            if (d_orig > 0) {
                while(d_orig % 2 == 0) { cur2--; d_orig /= 2; }
                while(d_orig % 3 == 0) { cur3--; d_orig /= 3; }
                while(d_orig % 5 == 0) { cur5--; d_orig /= 5; }
                while(d_orig % 7 == 0) { cur7--; d_orig /= 7; }
            }
            
            if (first_zero != -1 && i > first_zero) continue;
            
            for (int d = num[i] - '0' + 1; d <= 9; ++d) {
                int rem2 = max(0, req2 - cur2), rem3 = max(0, req3 - cur3);
                int rem5 = max(0, req5 - cur5), rem7 = max(0, req7 - cur7);
                
                int temp_d = d;
                while(temp_d % 2 == 0) { rem2--; temp_d /= 2; }
                while(temp_d % 3 == 0) { rem3--; temp_d /= 3; }
                while(temp_d % 5 == 0) { rem5--; temp_d /= 5; }
                while(temp_d % 7 == 0) { rem7--; temp_d /= 7; }
                
                rem2 = max(0, rem2); rem3 = max(0, rem3); rem5 = max(0, rem5); rem7 = max(0, rem7);
                
                int rem_len = n - 1 - i;
                if (get_min_len(rem2, rem3, rem5, rem7) <= rem_len) {
                    string res = num.substr(0, i) + to_string(d);
                    int ones = rem_len - get_min_len(rem2, rem3, rem5, rem7);
                    res.append(ones, '1');
                    
                    for(int pos = res.size(); pos < n; ++pos) {
                        for(int next_d = 2; next_d <= 9; ++next_d) {
                            int n2 = rem2, n3 = rem3, n5 = rem5, n7 = rem7;
                            int v = next_d;
                            while(v % 2 == 0) { n2--; v /= 2; }
                            while(v % 3 == 0) { n3--; v /= 3; }
                            while(v % 5 == 0) { n5--; v /= 5; }
                            while(v % 7 == 0) { n7--; v /= 7; }
                            
                            n2 = max(0, n2); n3 = max(0, n3); n5 = max(0, n5); n7 = max(0, n7);
                            
                            if (get_min_len(n2, n3, n5, n7) <= n - 1 - pos) {
                                res += to_string(next_d);
                                rem2 = n2; rem3 = n3; rem5 = n5; rem7 = n7;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }
        
        int target_len = max(n + 1, get_min_len(req2, req3, req5, req7));
        string res = "";
        int rem2 = req2, rem3 = req3, rem5 = req5, rem7 = req7;
        
        for(int pos = 0; pos < target_len; ++pos) {
            for(int next_d = 1; next_d <= 9; ++next_d) {
                int n2 = rem2, n3 = rem3, n5 = rem5, n7 = rem7;
                int v = next_d;
                while(v % 2 == 0) { n2--; v /= 2; }
                while(v % 3 == 0) { n3--; v /= 3; }
                while(v % 5 == 0) { n5--; v /= 5; }
                while(v % 7 == 0) { n7--; v /= 7; }
                
                n2 = max(0, n2); n3 = max(0, n3); n5 = max(0, n5); n7 = max(0, n7);
                
                if (get_min_len(n2, n3, n5, n7) <= target_len - 1 - pos) {
                    res += to_string(next_d);
                    rem2 = n2; rem3 = n3; rem5 = n5; rem7 = n7;
                    break;
                }
            }
        }
        return res;
    }
};