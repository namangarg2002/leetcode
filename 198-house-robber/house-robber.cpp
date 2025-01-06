class Solution {
public:
    int solveUsingMemoization(vector<int>&nums, int index, vector<int>&dp){
        // base case
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // recurssion relation
        int include = nums[index] + solveUsingMemoization(nums, index+2, dp);
        int exclude = 0 + solveUsingMemoization(nums, index+1, dp);

        dp[index] = max(include, exclude);

        return dp[index];
    }


    int solveUsingRecurssion(vector<int>& nums, int index){
        // base case
        if(index >= nums.size()){
            return 0;
        }

        // recurssion relation
        int include = nums[index] + solveUsingRecurssion(nums, index+2);
        int exclude = 0 + solveUsingRecurssion(nums, index+1);

        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        // from L->R direction

        // // solve Using Recurssion
        // int index = 0;
        // int ans = solveUsingRecurssion(nums, index);

        // solve using Memoization
        int index = 0;
        int n = nums.size();
        vector<int>dp(n+1, -1);
        int ans = solveUsingMemoization(nums, index, dp);

        return ans;
    }
};