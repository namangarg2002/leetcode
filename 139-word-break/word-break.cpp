class Solution {
public:
    bool check(vector<string>& wordDict, string&s){
        for(const auto&i:wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solveMem(string &s, vector<string>& wordDict, int start, vector<int>&dp){
        if(start == s.size()){
            return true;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        // one case solve
        string word = "";
        for(int i=start; i<s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                if(solveMem(s, wordDict, i+1, dp)){
                    return dp[start]  = true;
                }
            }
        }
        dp[start] = false;

        return dp[start];
    }
    bool solveTab(string &s, vector<string>& wordDict){
        vector<int>dp(s.size()+1, 0);

        dp[s.size()] = true;

        for(int start=s.size()-1; start>=0; start--){
            // one case solve
            string word = "";
            for(int i=start; i<s.size(); i++){
                word += s[i];
                if(check(wordDict, word)){
                    if(dp[i+1]){
                        dp[start]  = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // // Recursive Approach
        // return solveRE(s, wordDict, 0);

        // // Memoiation Approach
        // vector<int>dp(s.size()+1, -1);
        // return solveMem(s, wordDict, 0, dp);

        // tabulation Approach
        return solveTab(s, wordDict);
    }
};