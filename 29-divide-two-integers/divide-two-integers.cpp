class Solution {
public:
    int getQuotient(long long dividend, long long divisor) {
        long long s = 0, e = dividend / divisor; // Optimized range
        long long ans = 0;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long product = mid * divisor;

            if (product == dividend) return mid;
            else if (product < dividend) {
                ans = mid; // Store potential answer
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Convert to long long to prevent overflow
        long long num = abs((long long)dividend);
        long long den = abs((long long)divisor);

        // Use binary search to find quotient
        long long ans = getQuotient(num, den);

        // Apply sign
        return (dividend < 0) ^ (divisor < 0) ? -ans : ans;
    }
};