class Solution {
public:
    int solveUsingRecursion(string &a, string &b, int i, int j){
        // base case
        if(i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }

        // recursive relation
        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingRecursion(a, b, i+1, j+1);
        }else{
            int replace = 1 + solveUsingRecursion(a, b, i+1, j+1);
            int insert = 1 + solveUsingRecursion(a, b, i, j+1);
            int remove = 1 + solveUsingRecursion(a, b, i+1, j);

            ans = min(replace, min(insert, remove));
        }
        return ans;
    }

    int solveUsingMemoization(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // recursive relation
        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingMemoization(a, b, i+1, j+1, dp);
        }else{
            int replace = 1 + solveUsingMemoization(a, b, i+1, j+1, dp);
            int insert = 1 + solveUsingMemoization(a, b, i, j+1, dp);
            int remove = 1 + solveUsingMemoization(a, b, i+1, j, dp);

            ans = min(replace, min(insert, remove));
        }
        dp[i][j] = ans;

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        // // recursive Aprroach
        // int ans = solveUsingRecursion(word1, word2, 0, 0);

        // Memoization approach
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        int ans = solveUsingMemoization(word1, word2, 0, 0, dp);

        return ans;
    }
};