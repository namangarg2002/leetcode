class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int len = INT_MAX;
        int sum = 0;

        while(e < nums.size()){
            // sum m include karo
            sum = sum + nums[e];
            // ho sakta hai sum == target ho
            // ho sakta hai sum > target ho
            // ho sakta hai sum < target ho

            // minimize the indow size -> sum == target, sum > target 
            // explore -> sum < target
            while(sum >= target){
                // minimize
                len = min(len, e-s+1);
                // current element pointed by start,  should be removed from sum
                sum = sum - nums[s];
                s++;
            }
            // lopp se bhar matlab, gurantee -> sum < target
            // explore
            e++; 
        }
        return (len == INT_MAX) ? 0 : len;
    }
};