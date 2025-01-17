class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums, int index, int sum, int &target){
        // base case
        if(index >= nums.size()){
            return false;
        }
        if(sum > target){
            return false;
        }
        if(sum == target){
            return true;
        }

        // recursive relation
        int include = solveUsingRecursion(nums, index+1, sum+nums[index], target);
        int exclude = solveUsingRecursion(nums, index+1, sum, target);

        bool ans = include|exclude;

        return ans;
    }
    bool solveUsingMemoiation(vector<int>& nums, int index, int sum, int &target, vector<vector<int>>&dp){
        if(index >= nums.size()){
            return false;
        }
        if(sum > target){
            return false;
        }
        if(sum == target){
            return true;
        }

        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        int include = solveUsingMemoiation(nums, index+1, sum+nums[index], target, dp);
        int exclude = solveUsingMemoiation(nums, index+1, sum, target, dp);

        int ans = include|exclude;

        dp[index][sum] = ans;

        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalSum = 0;

        int n = nums.size();
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        if(totalSum & 1){
            // odd cannot be partitioned
            return false;
        }
        int target = totalSum / 2;
        int currSum = 0;

        // // // Recursive Approach
        // bool ans = solveUsingRecursion(nums, index, currSum, target);

        // memoization
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        bool ans = solveUsingMemoiation(nums, index, currSum, target, dp);
        return ans;
    }
};