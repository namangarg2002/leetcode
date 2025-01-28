class Solution {
public:
    int solveRE(vector<int>& prices, int i, int buy, int limit){
        // base case
        if(i>=prices.size() || limit == 0) return 0;

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
    int solveTab(vector<int>& prices, int &k){
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = dp[i+1][0][limit] + (-prices[i]);
                        int skipProfit = dp[i+1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }else{
                        int sellItProfit = prices[i] + dp[i+1][1][limit-1];
                        int skipProfit = dp[i+1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int solveTabSO(vector<int>& prices, int &k){
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        vector<vector<int>>next(2, vector<int>(k+1, 0));

        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = next[0][limit] + (-prices[i]);
                        int skipProfit = next[1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }else{
                        int sellItProfit = prices[i] + next[1][limit-1];
                        int skipProfit = next[0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        // // Recursive Approach
        // return solveRE(prices, 0, true, k);

        // // memoiation Approach
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solveMem(prices, 0, true, k, dp);

        //  // Tabulation Approach
        // return solveTab(prices, k);

        // space optimised Approach
        return solveTabSO(prices, k);
    }
};