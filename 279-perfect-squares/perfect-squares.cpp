class Solution {
public:
    int numSquareHelper(int n, vector<int>&dp){
        // base case
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i<=end){
            int perfectSquare = i * i;
            int numberofPerfectSquare = 1 + numSquareHelper(n-perfectSquare, dp);
            if(numberofPerfectSquare < ans){
                ans = numberofPerfectSquare;
            }
            i++;
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return numSquareHelper(n, dp)-1;
    }
};