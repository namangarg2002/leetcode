class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorA = 0, xorB = 0;

        // Calculate XOR of all elements in a
        for (int num : nums1) {
            xorA ^= num;
        }

        // Calculate XOR of all elements in b
        for (int num : nums2) {
            xorB ^= num;
        }

        // Determine the contribution of XOR based on the parity of the array sizes
        int result = 0;
        if (nums2.size() % 2 == 1) {
            result ^= xorA;
        }
        if (nums1.size() % 2 == 1) {
            result ^= xorB;
        }

        return result;
    }
};