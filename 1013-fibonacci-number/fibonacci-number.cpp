class Solution {
public:
    int solveUsingRecursion(int n){
        // base case
        if(n==0 || n==1){
            return n;
        }

        // recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }

    // top-down approach
    // rec + memoization(top-down) approach

    int solveUsingMemoization(int n, vector<int>&dp){
        // base case
        if(n==0 || n==1){
            return n;
        }
        // step3: if ans already exist then return ans;
        if(dp[n] != -1){
            return dp[n];
        }

        // recursive relation
        // Step2: Store and return using dp array
        dp[n] = solveUsingMemoization(n-1, dp) + solveUsingMemoization(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        // int ans = solveUsingRecursion(n);
        // return ans;

        // Step1: create dp array;
        vector<int>dp(n+1, -1);
        int ans = solveUsingMemoization(n, dp);
        return ans;
    }

};