class Solution {
public:
    int topdown(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + topdown(nums, curr+1, curr, dp);
        }
        int exclude = topdown(nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size(), -1));
        int ans = topdown(nums, curr, prev, dp);
        return ans;
    }
};