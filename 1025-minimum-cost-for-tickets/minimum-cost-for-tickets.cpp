class Solution {
public:
    int mincostTicketsHelper(vector<int>& days, vector<int>& costs, int i, vector<int>&dp){
        // base case
        if(i>=days.size()) return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        // solution for a case
        int ans = INT_MAX;
        // 1 day pass taken
        int cost1 = costs[0] + mincostTicketsHelper(days, costs, i+1, dp);

        // 7 Day Pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost7 = costs[1] + mincostTicketsHelper(days, costs, j, dp);

        // 30 Day Pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j<days.size() && days[j] <= passEndDay ){
            j++;
        }
        int cost30 = costs[2] + mincostTicketsHelper(days, costs, j, dp);

        ans = min(cost1, min(cost7, cost30));

        dp[i] = ans;

        return dp[i];
        
    }


    int mincostTicketsHelper(vector<int>& days, vector<int>& costs){
        vector<int>dp(days.size()+1, 0);

        dp[days.size()] = 0;

        int ans = INT_MAX;
        for(int index=days.size()-1; index>=0; index--){
            // 1 day pass taken
            int cost1 = costs[0] + dp[index+1];

            // 7 Day Pass taken
            int passEndDay = days[index] + 7 - 1;
            int j = index;
            while(j<days.size() && days[j] <= passEndDay ){
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30 Day Pass taken
            passEndDay = days[index] + 30 - 1;
            j = index;
            while(j<days.size() && days[j] <= passEndDay ){
                j++;
            }
            int cost30 = costs[2] + dp[j];

            ans = min(cost1, min(cost7, cost30));
            dp[index] = ans;
        }

        return dp[0];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int>dp(days.size()+1, -1);
        return mincostTicketsHelper(days, costs);
    }
};