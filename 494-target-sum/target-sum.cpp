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
    int findTargetSumWays(vector<int>& nums, int target) {
        // // Recursive Approach
        // return solveRE(nums, target, 0);

        // Memoiation Approach
        map<pair<int, int>, int>dp; // {i, target} -> no.ways
        return solveMem(nums, target, 0, dp);
    }
};