class Solution {
public:
    // Recurssive Approach 
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

    // Memoization Approach 
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

    // Tabulation approach
    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n, -1);

        dp[n-1] = nums[n-1];

        for(int index=n-2; index>=0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        // from L->R direction

        // // solve Using Recurssion
        // int index = 0;
        // int ans = solveUsingRecurssion(nums, index);

        // // solve using Memoization
        // int index = 0;
        // int n = nums.size();
        // vector<int>dp(n+1, -1);
        // int ans = solveUsingMemoization(nums, index, dp);

        // solve using tabulation
        int ans = solveUsingTabulation(nums);

        return ans;
    }
};