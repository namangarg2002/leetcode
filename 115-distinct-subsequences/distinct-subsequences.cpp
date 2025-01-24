class Solution {
public:
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        // base case
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i]==t[j]){
            ans += solveMem(s, t, i+1, j+1, dp);
        }
        ans += solveMem(s, t, i+1, j, dp);

        dp[i][j] = ans;
        
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        // // Recursive Approach
        // return solveRE(s, t, 0, 0); 

        // Memoiation Apprioach
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solveMem(s, t, 0, 0, dp);
    }
};