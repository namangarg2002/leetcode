class Solution {
public:
    int solveRE(vector<int>& piles, int index, int M, bool alice){
        if(index == piles.size()){
            return 0;
        }

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X=1; X<=2*M; X++){
            if(index+X-1 >= piles.size()) break;
            total += piles[index+X-1];
            if(alice){
                ans = max(ans, total + solveRE(piles, index + X, max(X, M), !alice));
            }else{
                ans = min(ans, solveRE(piles, index + X, max(X, M), !alice));
            }
        }
        return ans;
    }

    int solveMem(vector<int>& piles, int index, int M, bool alice, vector<vector<vector<int>>>&dp){
        if(index == piles.size()){
            return 0;
        }

        if(dp[index][M][alice] != -1){
            return dp[index][M][alice];
        }

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int X=1; X<=2*M; X++){
            if(index+X-1 >= piles.size()) break;
            total += piles[index+X-1];
            if(alice){
                ans = max(ans, total + solveMem(piles, index + X, max(X, M), !alice, dp));
            }else{
                ans = min(ans, solveMem(piles, index + X, max(X, M), !alice, dp));
            }
        }
        dp[index][M][alice] =  ans;

        return dp[index][M][alice];
    }
    int stoneGameII(vector<int>& piles) {

        // // recursion Approach
        // return solveRE(piles, 0, 1, true);

        // Memoiation Approach
        vector<vector<vector<int>>>dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2, -1)));
        return solveMem(piles, 0, 1, true, dp);
    }
};