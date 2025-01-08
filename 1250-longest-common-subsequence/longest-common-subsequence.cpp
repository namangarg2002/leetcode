class Solution {
public:
    int solveUsingRecursion(string a, string b, int i, int j){
        // base case
        if(i>=a.length() || j>=b.length()){
            return 0;
        }


        // recursive relations
        int ans = 0;
        if(a[i]==b[j]){
            ans =  1 + solveUsingRecursion(a, b, i+1, j+1);
        }
        else{
            ans =  max(solveUsingRecursion(a, b, i+1, j), solveUsingRecursion(a, b, i, j+1));
        }

        return ans;
    }

    int solveUsingMemoization(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i>=a.length() || j>=b.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // recursive relation
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveUsingMemoization(a, b, i+1, j+1, dp);
        }else{
            ans = max(solveUsingMemoization(a, b, i+1, j, dp), solveUsingMemoization(a, b, i, j+1, dp));
        }

        dp[i][j] = ans;

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // // recursive approach
        // int i=0;
        // int j=0;
        // int ans = solveUsingRecursion(text1, text2, i, j);

        // Memoization Approach
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        int ans = solveUsingMemoization(text1, text2, 0, 0, dp);

        return ans;
    }
};