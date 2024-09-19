class Solution {
public:
    int topDown(int amount, vector<int>& coins, int index, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size() || amount < 0){
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int include = topDown(amount - coins[index], coins, index, dp);
        int exclude = topDown(amount, coins, index+1, dp);

        return dp[index][amount] = include + exclude;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return topDown(amount, coins, 0, dp);
    }
};