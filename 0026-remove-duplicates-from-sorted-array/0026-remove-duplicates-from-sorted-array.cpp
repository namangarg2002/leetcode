class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer approach
        int i = 1, j = 0;
        while(i<nums.size()){
            if(nums[i]==nums[j])
            i++;
            else nums[++j] = nums[i++];
                    // OR
            // {
            //     j++;
            //     swap(nums[j], nums[i]);
            //     i++;
            // }
        }
        return j + 1;
    }
};