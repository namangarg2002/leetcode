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
    bool isInterleave(string s1, string s2, string s3) {
        // // Recursive Aproach
        // return solveRE(s1, s2, s3, 0, 0, 0);

        // Memoiation Approach
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solveMem(s1, s2, s3, 0, 0 , 0, dp);
    }
};