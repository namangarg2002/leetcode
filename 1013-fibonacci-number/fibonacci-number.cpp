class Solution {
public:
    int solveUsingRecursion(int n){
        // base case
        if(n==0 || n==1){
            return n;
        }

        // recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }

    // top-down approach
    // rec + memoization(top-down) approach

    int solveUsingMemoization(int n, vector<int>&dp){
        // base case
        if(n==0 || n==1){
            return n;
        }
        // step3: if ans already exist then return ans;
        if(dp[n] != -1){
            return dp[n];
        }

        // recursive relation
        // Step2: Store and return using dp array
        dp[n] = solveUsingMemoization(n-1, dp) + solveUsingMemoization(n-2, dp);
        return dp[n];
    }
    int solveUsingTabulation(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Step1: create an dp arry
        vector<int>dp(n+1, -1);

        // step2: analyse base case and fill dp array
        dp[0] = 0;
        dp[1] = 1;

        // step3: fill the remaining array
        // size = n+1
        // index-> 0 => n
        // index fill ho chuka hai -> 0 and 1
        // bacha kon sa index = 2 => n
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

    }

    int solveUsingTabSpaceOptimised(int n){
        // if (n == 0) return 0;
        // if (n == 1) return 1;
        
        // // Step1: create an dp arry
        // vector<int>dp(n+1, -1);

        // step2: analyse base case and fill dp array
        int prev = 0;
        if(n == 0)
            return 0;
        int curr = 1;
        if(n == 1){
            return 1;
        }

        // step3: fill the remaining array
        // size = n+1
        // index-> 0 => n
        // index fill ho chuka hai -> 0 and 1
        // bacha kon sa index = 2 => n

        int ans; 
        for(int i=2; i<=n; i++){
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;

    }


    int fib(int n) {
        // int ans = solveUsingRecursion(n);
        // return ans;

        // // Memoization steps
        // // Step1: create dp array;
        // vector<int>dp(n+1, -1);
        // int ans = solveUsingMemoization(n, dp);
        // return ans;

        // // tabulation Steps
        // int ans = solveUsingTabulation(n);

        int ans = solveUsingTabSpaceOptimised(n); 

        return ans;

    }

};