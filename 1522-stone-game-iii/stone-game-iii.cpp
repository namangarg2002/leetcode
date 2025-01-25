class Solution {
public:
    int solveRE(vector<int>& stoneValue, int index){
        if(index >= stoneValue.size()) return 0;

        int ans = INT_MIN;
        int total = 0;
        for(int X=1; X<=3; X++){
            if(index + X - 1 >= stoneValue.size()) break;
            total += stoneValue[index + X - 1];

            ans = max(ans, total - solveRE(stoneValue, index + X));
        }
        return ans;
    }
    int solveMem(vector<int>& stoneValue, int index, vector<int>&dp){
        if(index >= stoneValue.size()) return 0;

        if(dp[index] != -1){
            return dp[index];
        }
        int ans = INT_MIN;
        int total = 0;
        for(int X=1; X<=3; X++){
            if(index + X - 1 >= stoneValue.size()) break;
            total += stoneValue[index + X - 1];

            ans = max(ans, total - solveMem(stoneValue, index + X, dp));
        }
        dp[index] = ans;
        return dp[index];
    }
    int solveTab(vector<int>& stoneValue){
        vector<int>dp(stoneValue.size()+1, 0);

        for(int index=stoneValue.size()-1; index>=0; index--){
            int ans = INT_MIN;
            int total = 0;
            for(int X=1; X<=3; X++){
                if(index + X - 1 >= stoneValue.size()) break;
                total += stoneValue[index + X - 1];

                ans = max(ans, total - dp[index+X]);
            }
            dp[index] = ans;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // // Recursion Approach
        // int ans =  solveRE(stoneValue, 0); // A-B

        // // Memoiation Approach
        // vector<int>dp(stoneValue.size()+1, -1);
        // int ans = solveMem(stoneValue, 0, dp);

        // Tabulation Approach
        int ans = solveTab(stoneValue);

        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};