class Solution {
public:
    // Recurssive Approach
    int solveUsingRecurssion(vector<int>& coins, int amount){
        // base case
        if(amount == 0){
            return 0;
        }

        // recussive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            // find ans using ith coin
            // call recurssion only for valid amounts i.e., >=0 wale amounts
            if(amount - coins[i] >= 0){
                int recurssionKaAns = solveUsingRecurssion(coins, amount-coins[i]);
                // if a valid ans
                if(recurssionKaAns != INT_MAX){
                    // considering usage of ith coin
                    int ans = 1 + recurssionKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
        
    }

    // Memoization Approach
    int solveUsingMemoization(vector<int>& coins, int amount, vector<int>&dp){
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        // recussive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            // find ans using ith coin
            // call recurssion only for valid amounts i.e., >=0 wale amounts
            if(amount - coins[i] >= 0){
                int recurssionKaAns = solveUsingMemoization(coins, amount-coins[i], dp);
                // if a valid ans
                if(recurssionKaAns != INT_MAX){
                    // considering usage of ith coin
                    int ans = 1 + recurssionKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
        
    } 
    int coinChange(vector<int>& coins, int amount) {
        // // Recursive Approach
        // int ans = solveUsingRecurssion(coins, amount);

        // Memoization Approach
        int n = amount;
        vector<int>dp(n+1, -1);
        int ans = solveUsingMemoization(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};