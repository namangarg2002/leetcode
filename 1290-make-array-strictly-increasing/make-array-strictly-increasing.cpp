class Solution {
public:
    #define INF (1e9 + 1)
    int solveRE(vector<int>& arr1, vector<int>& arr2, int prev, int curr){
        // base case
        if(curr == arr1.size()) return 0;

        int opt1 = INF;
        if(prev < arr1[curr]){
            opt1 = solveRE(arr1, arr2, arr1[curr], curr+1); // no-operation
        }
        int opt2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[curr] = arr2[index];
            opt2 = 1 + solveRE(arr1, arr2, arr2[index], curr+1);
        }

        return min(opt1, opt2);
    }
    int solveMem(vector<int>& arr1, vector<int>& arr2, int prev, int curr, map<pair<int, int>, int>&dp){
        // base case
        if(curr == arr1.size()) return 0;

        if(dp.find({prev, curr}) != dp.end()) return dp[{prev, curr}];

        int opt1 = INF;
        if(arr1[curr] > prev){
            opt1 = solveMem(arr1, arr2, arr1[curr], curr+1, dp); // no-operation
        }
        int opt2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[curr] = arr2[index];
            opt2 = 1 + solveMem(arr1, arr2, arr2[index], curr+1, dp);
        }

        return dp[{prev, curr}] =  min(opt1, opt2);
        // return dp[prev+1][curr];
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        // // Recursive Approach
        // int ans = solveRE(arr1, arr2, -1, 0);

        // Memoiation Approach
        map<pair<int, int>, int>dp;
        int ans = solveMem(arr1, arr2, -1, 0, dp);

        return (ans == INF) ? -1 : ans;
    }
};