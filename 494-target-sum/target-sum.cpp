class Solution {
public:
    int solveRE(vector<int>& nums, int target, int i){
        if(i==nums.size()) return target == 0 ? 1 : 0;

        int minusWay = solveRE(nums, target-nums[i], i+1);
        int plusWay = solveRE(nums, target+nums[i], i+1);

        return minusWay+plusWay;
    }
    int solveMem(vector<int>& nums, int target, int i, map<pair<int, int>, int>&dp){
        if(i==nums.size()) return target == 0 ? 1 : 0;

        if(dp.find({i, target}) != dp.end()){
            return dp[{i, target}];
        }
        int minusWay = solveMem(nums, target-nums[i], i+1, dp);
        int plusWay = solveMem(nums, target+nums[i], i+1, dp);

        dp[{i, target}] = minusWay+plusWay;
        return dp[{i, target}];
    }
    // int solveTab(vector<int>& nums, int target){
    //     map<pair<int, int>, int>dp;
    //     dp[{nums.size(), 0}] = 1; // i==nums.size() and target==0

    //     int total = 0;
    //     for(auto num:nums){
    //         total += num;
    //     }
    //     for(int i=nums.size()-1; i>=0; i--){
    //         for(int target=-total; target <=total; target++){
    //             int minusWay = dp.find({i+1, target-nums[i]}) != dp.end() ? dp[{i+1, target-nums[i]}] : 0;
    //             int plusWay = dp.find({i+1, target+nums[i]}) != dp.end() ? dp[{i+1, target+nums[i]}] : 0;

    //             dp[{i, target}] = minusWay+plusWay;
    //         }
    //     }
    //     return dp[{0, target}];
    // }
    int solveTab(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if (abs(target) > total) return 0; 

        int offset = total;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * total + 1, 0));

        dp[nums.size()][offset] = 1; 

        for (int i = nums.size() - 1; i >= 0; i--) {
            vector<int> next(2 * total + 1, 0);
            for (int t = -total; t <= total; t++) {
                int shiftedT = t + offset;
                if (shiftedT - nums[i] >= 0)
                    next[shiftedT] += dp[i + 1][shiftedT - nums[i]];
                if (shiftedT + nums[i] < 2 * total + 1)
                    next[shiftedT] += dp[i + 1][shiftedT + nums[i]];
            }
            dp[i] = next;
        }
        
        return dp[0][target + offset];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // // Recursive Approach
        // return solveRE(nums, target, 0);

        // // Memoiation Approach
        // map<pair<int, int>, int>dp; // {i, target} -> no.ways
        // return solveMem(nums, target, 0, dp);

        // Tabulation Approach
        return solveTab(nums, target);
    }
};