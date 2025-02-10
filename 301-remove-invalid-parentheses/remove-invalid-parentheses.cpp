class Solution {
public:
    void solve(string& s,unordered_set<string>&ans, int invalidOpen, int invalidClose, int balance, int index, string &output){
        if(index >= s.length()){
            // valid answer
            if(invalidOpen == 0 && invalidClose == 0 && balance == 0){
                ans.insert(output);
            }
            return;
        }
        // // include/exclude
        // letter wala case
        if(s[index] != '(' && s[index] != ')'){
            output.push_back(s[index]);
            solve(s, ans, invalidOpen, invalidClose, balance, index+1, output);
            output.pop_back();
        }else{
            // brackets
            // 2 case -> ( and )
            // open Bracket
            if(s[index] == '('){
                // include / exclude
                // remove karu
                if(invalidOpen > 0){
                    solve(s, ans, invalidOpen-1, invalidClose, balance, index+1, output);
                }
                // remove na Karu
                output.push_back('(');
                solve(s, ans,invalidOpen, invalidClose, balance+1, index+1, output);
                output.pop_back();

            }else if(s[index] == ')'){
                // remove karu
                if(invalidClose > 0){
                    solve(s, ans, invalidOpen, invalidClose-1, balance, index+1, output);
                }
                // remove na karu
                // ap ek clode bracket pr khade ho, and previously koi nhi open bracket present nhi hai
                // toh kya mai ise remove na kru ?
                if(balance > 0){
                    // koi nakoi opening brachet present hai
                    output.push_back(')');
                    solve(s, ans, invalidOpen, invalidClose, balance-1, index+1, output);
                    output.pop_back();
                }
            }

        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int invalidOpen = 0;
        int invalidClose = 0;
        int balance = 0;
        int index = 0;
        string output = "";
        for(auto ch:s){
            if(ch=='('){
                invalidOpen++;
            }else if(ch==')'){
                if(invalidOpen){
                    invalidOpen--;
                }else{
                   invalidClose++; 
                }
            }
        }
        solve(s, ans, invalidOpen, invalidClose, balance, index, output);

        return vector<string>(ans.begin(), ans.end());
    }
};