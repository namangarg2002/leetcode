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
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end()); 

        // // Recursive Approach
        // return solveRE(satisfaction, 0, 1);

        // Memoiation Approach
        vector<vector<int>>dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1, -1));
        return solveMem(satisfaction, 0, 1, dp);
    }
};