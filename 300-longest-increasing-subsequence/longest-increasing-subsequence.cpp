class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev){
        // base case
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingRecursion(nums, curr+1, curr);
        }

        int exclude = 0 + solveUsingRecursion(nums, curr+1, prev);
        int ans = max(include, exclude);
        return ans;

    }

    int solveUsingMemoization(vector<int>& nums, int curr, int prev, vector<vector<int>>&dp){
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMemoization(nums, curr+1, curr, dp);
        }
        int exclude = 0 + solveUsingMemoization(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(include, exclude);

        return dp[curr][prev+1];
    }

    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int curr_index=n-1; curr_index>=0; curr_index--){
            for(int prev_index=curr_index-1; prev_index>=-1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + dp[curr_index+1][curr_index+1];
                }
                int exclude = 0 + dp[curr_index+1][prev_index+1];

                dp[curr_index][prev_index+1] = max(include, exclude);
            }
        }
        return dp[0][0];

    }
    int solveUsingTabulationSpaceOptimization(vector<int>& nums){
        int n = nums.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int curr_index=n-1; curr_index>=0; curr_index--){
            for(int prev_index=curr_index-1; prev_index>=-1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + next[curr_index+1];
                }
                int exclude = 0 + next[prev_index+1];

                curr[prev_index+1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int lengthOfLIS(vector<int>& nums) {

        // // Recusive Approach
        // int curr = 0;
        // int prev = -1;
        // int ans = solveUsingRecursion(nums, curr, prev);

        // // Memoization Approach
        // int curr = 0;
        // int prev = -1;
        // int n = nums.size(); 
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMemoization(nums, curr, prev, dp);

        // // Tabulation Method
        // int ans = solveUsingTabulation(nums);

        // Space Optimization 
        int ans = solveUsingTabulationSpaceOptimization(nums);

        return ans;
    }
};