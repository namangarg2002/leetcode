class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, map<pair<int,int>, int> &maxi, int s, int e){
        // base case
        if(s >= e){
            return 0;
        }

        int ans = INT_MAX;
        for(int i=s; i<e; i++){
            // i is used here for partitioning
            ans = min(ans, (maxi[{s, i}]*maxi[{i+1, e}]) + solveUsingRecursion(arr, maxi, s, i) + solveUsingRecursion(arr, maxi, i+1, e));
        }
        return ans;
    }
    int solveUsingMemoization(vector<int>& arr, map<pair<int,int>, int> &maxi, int s, int e, vector<vector<int>>&dp){
        if(s >= e){
            return 0;
        }

        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s; i<e; i++){
            ans = min(ans, maxi[{s, i}]*maxi[{i+1, e}] + solveUsingMemoization(arr, maxi, s, i, dp) + solveUsingMemoization(arr, maxi, i+1, e, dp));
        }
        dp[s][e] = ans;

        return dp[s][e];
    }

    int solveUsingTabulation(vector<int>& arr, map<pair<int,int>, int> &maxi){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)); 

        for(int s_index=n-1; s_index>=0; s_index--){
            for(int e_index=0; e_index<=n-1; e_index++){
                if(s_index >= e_index){
                    continue;
                }
                int ans = INT_MAX;
                for(int i=s_index; i<e_index; i++){
                    ans = min(ans, maxi[{s_index, i}]*maxi[{i+1, e_index}] + dp[s_index][i] + dp[i+1][e_index]);
                }
                dp[s_index][e_index] = ans;

            }
        }
        return dp[0][n-1];

    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // precomputation
        map<pair<int,int>, int> maxi;
        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        // // Recursive Approach
        // int start = 0;
        // int end = n - 1;
        // int ans = solveUsingRecursion(arr, maxi, start, end);

        // // Memoization Approach
        // int start = 0;
        // int end = n-1;
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); 
        // int ans = solveUsingMemoization(arr, maxi, start, end, dp);

        // Tabulation Approach
        int ans = solveUsingTabulation(arr, maxi);

        return ans;
    }
};