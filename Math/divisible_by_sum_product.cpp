class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        long long sum = 0;
        long long prod = 1;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            prod *= digit;
            temp /= 10;
        }
        
        long long total = sum + prod;
        return (n % total) == 0;
    }
};