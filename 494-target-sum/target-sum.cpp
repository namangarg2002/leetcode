class Solution {
public:
    int solveRE(vector<int>& nums, int target, int i){
        if(i==nums.size()) return target == 0 ? 1 : 0;

        // int possibleWays = 0;
        int minusWay = solveRE(nums, target-nums[i], i+1);
        int plusWay = solveRE(nums, target+nums[i], i+1);

        return minusWay+plusWay;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solveRE(nums, target, 0);
    }
};