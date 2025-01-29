class Solution {
public:
    int solveRE(vector<int>& sat, int i, int time){
        if(i>=sat.size()) return 0;

        int include = time*sat[i] + solveRE(sat, i+1, time+1);
        int exclude = 0 + solveRE(sat, i+1, time);

        return max(include, exclude);
    }
    int solveMem(vector<int>& sat, int i, int time, vector<vector<int>>&dp){
        if(i>=sat.size()) return 0;

        if(dp[i][time] != -1) return dp[i][time];

        int include = time*sat[i] + solveMem(sat, i+1, time+1, dp);
        int exclude = 0 + solveMem(sat, i+1, time, dp);

        return dp[i][time] = max(include, exclude);
    }
    int solveTab(vector<int>& sat){
        vector<vector<int>>dp(sat.size()+1, vector<int>(sat.size()+2, 0));

        for(int i=sat.size()-1; i>=0; i--){
            for(int time=sat.size(); time>=1; time--){
                int include = time*sat[i] + dp[i+1][time+1];
                int exclude = 0 + dp[i+1][time];

                dp[i][time] = max(include, exclude);
            }
        }
        return dp[0][1];
    }
    int solveTabSO(vector<int>& sat){
        vector<int>curr(sat.size()+2, 0);
        vector<int>next(sat.size()+2, 0);

        for(int i=sat.size()-1; i>=0; i--){
            for(int time=sat.size(); time>=1; time--){
                int include = time*sat[i] + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end()); 

        // // Recursive Approach
        // return solveRE(satisfaction, 0, 1);

        // // Memoiation Approach
        // vector<vector<int>>dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1, -1));
        // return solveMem(satisfaction, 0, 1, dp);

        // // Tabulation Approach
        // return solveTab(satisfaction);

        // Space optimization
        return solveTabSO(satisfaction);
    }
};