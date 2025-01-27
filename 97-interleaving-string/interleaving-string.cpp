class Solution {
public:
    bool solveRE(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        bool flag = false;
        if(i<s1.size() && s1[i] == s3[k]){
            flag = flag || solveRE(s1, s2, s3, i+1, j, k+1);
        }
        if(j<s2.size() && s2[j] == s3[k]){
            flag = flag || solveRE(s1, s2, s3, i, j+1, k+1);
        }
        return flag;
    }
    bool solveMem(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(i<s1.size() && s1[i] == s3[k]){
            flag = flag || solveMem(s1, s2, s3, i+1, j, k+1, dp);
        }
        if(j<s2.size() && s2[j] == s3[k]){
            flag = flag || solveMem(s1, s2, s3, i, j+1, k+1, dp);
        }
        dp[i][j] = flag;
        return dp[i][j];
    }
    bool solveTab(string &s1, string &s2, string &s3){
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool>>dp(s1.size()+1, vector<bool>(s2.size()+1, false));

        dp[s1.size()][s2.size()] = true;
        for(int i=s1.size(); i>=0; i--){
            for(int j=s2.size(); j>=0; j--){
                int k = i + j;
                if(i<s1.size() && s1[i] == s3[k]){
                    dp[i][j] = dp[i][j] || dp[i+1][j];
                }
                if(j<s2.size() && s2[j] == s3[k]){
                    dp[i][j] = dp[i][j] || dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        // // Recursive Aproach
        // return solveRE(s1, s2, s3, 0, 0, 0);

        // // Memoiation Approach
        // vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        // return solveMem(s1, s2, s3, 0, 0 , 0, dp);

        // Tabulation Approach
        return solveTab(s1, s2, s3);
    }
};