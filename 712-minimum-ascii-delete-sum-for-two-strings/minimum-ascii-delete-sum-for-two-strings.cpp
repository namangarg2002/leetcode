class Solution {
public:
    int solveMem(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        int cost = 0;
        if(i==s1.size() || j==s2.size()){
            // return the sum of Ascii of remaining char of remaining string of s1 string 
            for(int x=i; x<s1.size(); x++){
                cost += s1[x];
            }

            for(int x=j; x<s2.size(); x++){
                cost += s2[x];
            }
            return cost;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else if(s1[i] == s2[j]){
            cost = solveMem(s1, s2, i+1, j+1, dp);
        }else{
            int cost1 = s1[i] + solveMem(s1, s2, i+1, j, dp);
            int cost2 = s2[j] + solveMem(s1, s2, i, j+1, dp);

            cost = min(cost1, cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }
    int solveTab(string &s1, string &s2){
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // initialize base case when one of the the string is empty
        for(int i=s1.size()-1; i>=0; i--){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int i=s2.size()-1; i>=0; i--){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }

        int cost = 0;
        for(int i=s1.size()-1; i>=0; i--){
            for(int j=s2.size()-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];
                }else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];

                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        // vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        // return solveMem(s1, s2, 0, 0, dp);
        return solveTab(s1, s2);
    }
};