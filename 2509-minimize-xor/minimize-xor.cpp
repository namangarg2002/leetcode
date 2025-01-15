class Solution {
public:
    int minimizeXor(int num1, int num2) {
       // Count the number of set bits in num2
        int countBits = __builtin_popcount(num2);
        
        int result = 0;
        // Set bits from the most significant bit to the least in num1
        for (int i = 31; i >= 0 && countBits > 0; --i) {
            if ((num1 & (1 << i)) != 0) {
                result |= (1 << i);
                --countBits;
            }
        }

        // If there are still bits to be set, set them from the least significant bit
        for (int i = 0; i < 32 && countBits > 0; ++i) {
            if ((result & (1 << i)) == 0) {
                result |= (1 << i);
                --countBits;
            }
        }

        return result;
    }
};