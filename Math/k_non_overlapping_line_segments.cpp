/*
{
    "problem_name": "Number of Sets of K Non-Overlapping Line Segments",
    "category": "Math",
    "time_complexity": "O(K)",
    "space_complexity": "O(1)"
}
*/

class Solution {
private:
    // Core function to calculate (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1000000007;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Fermat's Little Theorem for Modular Multiplicative Inverse
    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;
        int N = n + k - 1; // Total points after adding dummy gaps
        int K = 2 * k;     // Endpoints to choose

        // Edge case: Not enough points to form K segments
        if (K > N) return 0;

        long long num = 1, den = 1;
        
        // Calculating Combinations (N C K) % MOD in O(K) time
        for (int i = 0; i < K; i++) {
            num = (num * (N - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }
};