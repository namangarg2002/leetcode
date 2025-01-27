class Solution {
public:
    int solveRE(vector<int>& nums, int s, int e){
        // base case
        if(s > e) return 0;
        int coins = INT_MIN;
        for(int i=s; i<=e; i++){
            coins = max(coins, nums[s-1]*nums[i]*nums[e+1] + solveRE(nums, s, i-1) + solveRE(nums, i+1, e));

        }
        return coins;
    }

    int solveMem(vector<int>& nums, int s, int e, vector<vector<int>>&dp){
        // base case
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int coins = INT_MIN;
        for(int i=s; i<=e; i++){
            coins = max(coins, nums[s-1]*nums[i]*nums[e+1] + solveMem(nums, s, i-1, dp) + solveMem(nums, i+1, e, dp));

        }
        dp[s][e] = coins;

        return dp[s][e];
    }
    int solveTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0));

        for(int s=nums.size()-2; s>=1; s--){
            for(int e=1; e<=nums.size()-2; e++){
                long long coins = LLONG_MIN;
                for(int i=s; i<=e; i++){
                    coins = max(coins, 1LL*nums[s-1]*nums[i]*nums[e+1] + dp[s][i-1] + dp[i+1][e]);

                }
                dp[s][e] = coins;
            }
        }
        return dp[1][nums.size()-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int start = 1;
        int end = nums.size()-2;

        // // Recursive Approach
        // return solveRE(nums, start, end);

        // // Memoiation Approch
        // vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveMem(nums, start, end, dp);

        // TabulationApproach
        return solveTab(nums);
    }
};