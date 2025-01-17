class Solution {
public:
    long long mod = 1e9+7;
    int solveUsingRecursion(int n, int &k, int target){
        //base case
        if(target < 0){
            return 0;
        }
        if(n==0 && target != 0){
            return 0;
        }
        if(n==0 && target == 0){
            return 1;
        }

        // recursive relation
        int ans = 0;
        for(int i=1; i<=k; i++){
            ans += solveUsingRecursion(n-1, k, target-i);
        }

        return ans;

    }

    int solveUsingMemoiation(int n, int &k, int target, vector<vector<int>>&dp){
        if(target < 0){
            return 0;
        }
        if(n==0 && target != 0){
            return 0;
        }
        if(n==0 && target == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + solveUsingMemoiation(n-1, k, target-i, dp)) % mod;
        }
        dp[n][target] = ans;

        return dp[n][target];
    }

    int solveUsingTabulation(int n, int k, int target){
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));

        dp[0][0] = 1;

        for(int diceUsed=1; diceUsed<=n; diceUsed++){
            for(int currSum=0; currSum<=target; currSum++){
                int ans = 0;
                for(int face=1; face<=k; face++){
                    if(currSum - face >= 0){
                        ans = (ans + dp[diceUsed-1][currSum-face]) % mod;
                    }
                }
                dp[diceUsed][currSum] = ans;
            }
        }

        return dp[n][target];
    }

    int solveUsingSo(int n, int &k, int target){
        vector<int>prev(target+1, 0);
        vector<int>curr(target+1, 0);

        prev[0] = 1;

        for(int diceUsed=1; diceUsed<=n; diceUsed++){
            for(int currSum=0; currSum<=target; currSum++){
                int ans = 0;
                for(int face=1; face<=k; face++){
                    if(currSum - face >= 0){
                        ans = (ans + prev[currSum-face]) % mod;
                    }
                }
                curr[currSum] = ans;
            }
            prev = curr;
        }

        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // // Recursive Approach
        // int ans = solveUsingRecursion(n, k, target);

        // // Memoiation Approach
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // int ans = solveUsingMemoiation(n, k, target, dp);

        // // Tabulation Approach
        // int ans = solveUsingTabulation(n, k, target);

        // space optimization
        int ans = solveUsingSo(n, k, target);

        return ans;
    }
};