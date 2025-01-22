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

    int numSquareHelper(int n){
        vector<int>dp(n+1, 0);

        dp[0] = 1;

        for(int i=1; i<=n; i++){
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(n);
            while(start<=end){
                int perfectSquare = start * start;
                int numberofPerfectSquare = 1 + dp[start-perfectSquare];
                if(numberofPerfectSquare < ans){
                    ans = numberofPerfectSquare;
                }
                i++;
            }
        }

        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return numSquareHelper(n, dp)-1;
    }
};