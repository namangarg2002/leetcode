class Solution {
public:
    int solveRE(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];

        // diff = P1 - P2;
        int diffByStart = nums[start] - solveRE(nums, start+1, end);
        int diffByEnd = nums[end] - solveRE(nums, start, end-1);

        return max(diffByStart, diffByEnd);
    }
    int solveMem(vector<int>& nums, int start, int end, vector<vector<int>>&dp){
        if(start==end) return nums[start];
        
        if(dp[start][end] != -1) return dp[start][end];

        int diffByStart = nums[start] - solveMem(nums, start+1, end, dp);
        int diffByEnd = nums[end] - solveMem(nums, start, end-1, dp);

        return dp[start][end] = max(diffByStart, diffByEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        // // Recursive Approach
        // int ans = solveRE(nums, 0, nums.size()-1);
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        int ans = solveMem(nums, 0, nums.size()-1, dp);

        return (ans >=0) ? true: false;
    }
};