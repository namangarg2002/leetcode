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
    int solveTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0));
        // base case
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= nums.size(); len++){
            for(int start = 0; start <= nums.size() - len; start++) {
                int end = start + len - 1;
                int diffByStart = nums[start] - dp[start+1][end];
                int diffByEnd = nums[end] - dp[start][end-1];

                dp[start][end] = max(diffByStart, diffByEnd);
            }
        }
        return dp[0][nums.size()-1];
    }
    int solveTabSO(vector<int>& nums){
        vector<int>curr(nums.size(), 0);
        vector<int>next(nums.size(), 0);

        // base case
        for (int i = 0; i < nums.size(); i++) {
            next[i] = nums[i];
        }

        for(int len = 2; len <= nums.size(); len++){
            for(int start = 0; start <= nums.size() - len; start++) {
                int end = start + len - 1;
                int diffByStart = nums[start] - next[end];
                int diffByEnd = nums[end] - next[end-1];

                curr[end] = max(diffByStart, diffByEnd);
            }
            next = curr;
        }
        return curr[nums.size()-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        // // Recursive Approach
        // int ans = solveRE(nums, 0, nums.size()-1);

        // // Memoiation Approach
        // vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        // int ans = solveMem(nums, 0, nums.size()-1, dp);

        // // tabulation approach
        // int ans = solveTab(nums);

        // Space optimization
        int ans = solveTabSO(nums);

        return (ans >=0) ? true: false;
    }
};