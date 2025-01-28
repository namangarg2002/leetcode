class Solution {
public:
    int solveRE(vector<int>&prices, int i, int buy, int&fee){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = solveRE(prices, i+1, 0, fee) + (-prices[i]); //at that day buy
            int skipProfit = solveRE(prices, i+1, 1, fee);
            profit = max(buyItProfit, skipProfit);
        }else{
            int sellItProfit = prices[i] + solveRE(prices, i+1, 1, fee) -fee;
            int skipProfit = solveRE(prices, i+1, 0, fee);
            profit = max(sellItProfit, skipProfit);
        }
        return profit;
    }
    int solveMem(vector<int>&prices, int i, int buy, int &fee, vector<vector<int>>&dp){
        if(i >= prices.size()) return 0;
        
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy){
            int buyItProfit = solveMem(prices, i+1, 0, fee, dp) + (-prices[i]);
            int skipProfit = solveMem(prices, i+1, 1, fee, dp);
            profit = max(buyItProfit, skipProfit);
        }else{
            int sellItProfit = prices[i] + solveMem(prices, i+1, 1, fee, dp) - fee;
            int skipProfit = solveMem(prices, i+1, 0, fee, dp);
            profit = max(sellItProfit, skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        // // Recursive Approach
        // return solveRE(prices, 0, true, fee);

        // Memoiation Approach
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return solveMem(prices, 0, true, fee, dp);
    }
};