class Solution {
public:
    int solveUsingRecursion(int start, int end){
        // base case
        // if(start > end){
        //     // range se bhar
        //     return 0;
        // }
        // if(start == end){
        //     // sirf ek hi no. hai
        //     return 0;
        // }
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max(solveUsingRecursion(start, i-1), solveUsingRecursion(i+1,end)));
        }

        return ans;
    }

    int solveUsingMemoization(int start, int end, vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max(solveUsingMemoization(start, i-1, dp), solveUsingMemoization(i+1, end, dp)));
        }

        dp[start][end] = ans;

        return dp[start][end];
    }
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;

        // // Recursive Approach
        // int ans = solveUsingRecursion(start, end);

        // Memoization Approach
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMemoization(start, end, dp);

        return ans;
    }
};