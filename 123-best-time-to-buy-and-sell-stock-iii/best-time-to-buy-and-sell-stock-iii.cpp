class Solution {
public:
    int solveRE(vector<int>& prices, int i, int buy, int limit){
        // base case
        if(i>=prices.size()) return 0;
        if(limit == 0) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = solveRE(prices, i+1, 0, limit) + (-prices[i]);
            int skipProfit = solveRE(prices, i+1, 1, limit);
            profit = max(buyItProfit, skipProfit);
        }else{
            int sellItProfit = prices[i] + solveRE(prices, i+1, 1, limit-1);
            int skipProfit = solveRE(prices, i+1, 0, limit);
            profit = max(sellItProfit, skipProfit);
        }
        return profit;
    }
    int solveMem(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>&dp){
        // base case
        if(i>=prices.size() || limit == 0) return 0;

        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }

        int profit = 0;
        if(buy){
            int buyItProfit = solveMem(prices, i+1, 0, limit, dp) + (-prices[i]);
            int skipProfit = solveMem(prices, i+1, 1, limit, dp);
            profit = max(buyItProfit, skipProfit);
        }else{
            int sellItProfit = prices[i] + solveMem(prices, i+1, 1, limit-1, dp);
            int skipProfit = solveMem(prices, i+1, 0, limit, dp);
            profit = max(sellItProfit, skipProfit);
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // // Recursive Approach
        // return solveRE(prices, 0, true, 2);

        // memoiation Approach
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveMem(prices, 0, true, 2, dp);
    }
};