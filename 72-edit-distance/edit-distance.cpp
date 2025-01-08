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

    int solveUsingTabulation(string &a, string &b){
        vector<int>curr(a.length()+1, 0);
        vector<int>next(a.length()+1, 0);

        // // base case analyse
        // for(int col=0; col<=b.length(); col++){
        //     curr[col] = b.length()-col;
        // }
        for(int row=0; row<=a.length(); row++){
            next[row] = a.length()-row;
        }
        for(int j_index=b.length()-1; j_index>=0; j_index--){
            for(int i_index=a.length()-1; i_index>=0; i_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    ans = 0 + next[i_index+1];
                }else{
                    int replace = 1 + next[i_index+1];
                    int insert = 1 + next[i_index];
                    int remove = 1 + curr[i_index+1];

                    ans = min(replace, min(insert, remove));
                }

                curr[i_index] = ans;
            }
            next = curr;
        }
        return next[0];

    }

    int solveUsingTabulationSpaceOptimization(string &a, string &b){
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, -1));

        // base case analyse
        for(int col=0; col<=b.length(); col++){
            dp[a.length()][col] = b.length()-col;
        }
        for(int row=0; row<=a.length(); row++){
            dp[row][b.length()] = a.length()-row;
        }

        for(int i_index=a.length()-1; i_index>=0; i_index--){
            for(int j_index=b.length()-1; j_index>=0; j_index--){
                int ans = 0;
                if(a[i_index] == b[j_index]){
                    ans = 0 + dp[i_index+1][j_index+1];
                }else{
                    int replace = 1 + dp[i_index+1][j_index+1];
                    int insert = 1 + dp[i_index][j_index+1];
                    int remove = 1 + dp[i_index+1][j_index];

                    ans = min(replace, min(insert, remove));
                }

                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];

    }

    int minDistance(string word1, string word2) {
        // // recursive Aprroach
        // int ans = solveUsingRecursion(word1, word2, 0, 0);

        // // Memoization approach
        // vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // int ans = solveUsingMemoization(word1, word2, 0, 0, dp);

        // // Tabulation Approach
        // int ans = solveUsingTabulation(word1, word2);

        // Space Optimization
        int ans = solveUsingTabulationSpaceOptimization(word1, word2);

        return ans;
    }
};