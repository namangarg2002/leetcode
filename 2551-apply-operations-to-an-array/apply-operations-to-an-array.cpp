class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
    
    // Step 1: Apply the given transformation rules
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    
    // Step 2: Move all nonzero elements to the left and push zeros to the right
    vector<int> result(n, 0);
    int index = 0;
    for (int num : nums) {
        if (num != 0) {
            result[index++] = num;
        }
    }
    
    return result;

    }
};