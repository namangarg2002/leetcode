class Solution {
public:
    // int solve(string& a, string& b, int i, int j){
    //     // base case
    //     if(i >= a.length()){
    //         // word1 wala string end hogai
    //         // means word1 ki length may be word2 se hoti hai
    //         return b.length() - j;
    //     }
    //     if(j >= b.length()){
    //         // word2 end hogaya
    //         // means word2 ki length may be word1 se choti hai
    //         return a.length() - i;
    //     }
    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         // ṃatch
    //         ans = 0 + solve(a, b, i+1, j+1);
    //     }
    //     else{
    //         // no match
    //         // operation perform karo
    //         // option1 -> insert
    //         int option1 = 1 + solve(a, b, i, j+1);
    //         // option2 -> remove
    //         int option2 = 1 + solve(a, b, i+1, j);
    //         // option3 -> replace
    //         int option3 = 1 + solve(a, b, i+1, j+1);

    //         ans = min(option1, min(option2,option3));
    //     }
    //     return ans;
    // }
    // int minDistance(string word1, string word2) {
    //     int i = 0;
    //     int j = 0;
    //     int ans = solve(word1, word2, i, j);
    //     return ans; 
    // }

    int solve(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        // bade case
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }

        int ans = 0;
        if(a[i] == b[j]){
            return solve(a, b, i+1, j+1, dp);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        else{
            // insert
            int insertAns = 1 + solve(a, b, i, j+1, dp);

            // delete
            int deleteAns = 1 + solve(a, b, i+1, j, dp);

            // replace
            int replaceAns = 1 + solve(a, b, i+1, j+1, dp);

            ans =  min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2){
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return solve(word1, word2, 0, 0, dp);
    }

}; 