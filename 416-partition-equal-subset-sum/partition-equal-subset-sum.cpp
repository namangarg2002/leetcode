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

        int ans = include||exclude;

        dp[index][sum] = ans;

        return dp[index][sum];
    }

    bool solveUsingTabulation(vector<int>& nums, int &target){
        int n = nums.size();
        vector<vector<int>>dp(n+2, vector<int>(target+1, 0));

        for(int row=0; row<=n; row++){
            dp[row][target] = 1;
        }

        for(int index=n-1; index>=0; index--){
            for(int sum=target; sum>=0; sum--){
                int include = 0;
                if(sum + nums[index] <= target){
                    include = dp[index+1][sum+nums[index]];
                }
                int exclude = dp[index+1][sum];

                dp[index][sum] = (include||exclude);
            }
        }

        return dp[0][0];
    }

    bool solveUsingTabulationSO(vector<int>& nums, int &target){
        int n = nums.size();

        // vector<vector<int>>dp(n+2, vector<int>(target+1, 0));
        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);

        // for(int row=0; row<=n; row++){
        //     dp[row][target] = 1;
        // }
        curr[target] = 1;
        next[target] = 1;

        for(int index=n-1; index>=0; index--){
            for(int sum=target; sum>=0; sum--){
                int include = 0;
                if(sum + nums[index] <= target){
                    include = next[sum+nums[index]];
                }
                int exclude = next[sum];

                curr[sum] = (include||exclude);
            }
            next = curr;
        }

        return next[0];
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

        // // memoization
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // bool ans = solveUsingMemoiation(nums, index, currSum, target, dp);

        // // Tabulation Approach
        // bool ans = solveUsingTabulation(nums, target);

        // Space Optimizaion Approach
        bool ans = solveUsingTabulationSO(nums, target);

        return ans;
    }
};