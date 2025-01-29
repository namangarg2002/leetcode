class Solution {
public:
    void convertStrToNumStrs(vector<string>& strs, vector<pair<int, int>>&numStr){
        for(auto str:strs){
            int zeros = 0;
            int ones = 0;
            for(auto ch:str){
                if(ch == '0') zeros++;
                else ones++;
            }
            numStr.push_back({zeros, ones});
        }
    }
    int solveRE(vector<pair<int, int>>&numStr, int i, int m, int n){
        if(i == numStr.size()) return 0;

        int zeroes = numStr[i].first;
        int ones = numStr[i].second;

        int include = 0;
        int exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0){
            include = 1 + solveRE(numStr, i+1, m-zeroes, n-ones);
        }
        exclude = 0 + solveRE(numStr, i+1, m, n);

        return max(include, exclude);
    }
    int solveMem(vector<pair<int, int>>&numStr, int i, int m, int n,vector<vector<vector<int>>>&dp){
        if(i == numStr.size()) return 0;
        
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroes = numStr[i].first;
        int ones = numStr[i].second;

        int include = 0;
        int exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0){
            include = 1 + solveMem(numStr, i+1, m-zeroes, n-ones, dp);
        }
        exclude = 0 + solveMem(numStr, i+1, m, n, dp);

        return dp[i][m][n] = max(include, exclude);
    }
    int solveTab(vector<pair<int, int>>&numStr, int &m, int &n){
        vector<vector<vector<int>>>dp(numStr.size() + 1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for(int i=numStr.size()-1; i>=0; i--){
            for(int m_index=0; m_index<=m ; m_index++){
                for(int n_index=0; n_index<=n; n_index++){
                    int zeroes = numStr[i].first;
                    int ones = numStr[i].second;

                    int include = 0, exclude = 0;
                    if(m_index - zeroes >= 0 && n_index - ones >= 0){
                        include = 1 + dp[i+1][m_index-zeroes][n_index-ones];
                    }
                    exclude = 0 + dp[i+1][m_index][n_index];;

                    dp[i][m_index][n_index] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>numStr; // {no. 0's, no. 1's};
        convertStrToNumStrs(strs, numStr);

        // // Recursive Approach
        // return solveRE(numStr, 0, m, n);

        // // Memoiation Approach
        // vector<vector<vector<int>>>dp(numStr.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        // return solveMem(numStr, 0, m, n, dp);

        // Tabulation Approach
        return solveTab(numStr, m, n);
    }
};