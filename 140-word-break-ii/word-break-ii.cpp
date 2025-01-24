class Solution {
public:
    bool check(string &word, unordered_map<string, bool> &dict){
        return dict.find(word) != dict.end();
    }
    vector<string> solveRE(string &s, unordered_map<string, bool>&dict, int start){
        if(start == s.size()){
            return {""};
        }

        vector<string>ans;
        string word = "";
        for(int i = start; i<s.size(); i++){
            word += s[i];
            if(check(word, dict)){
                vector<string> subResults = solveRE(s, dict, i + 1);

                for (const auto &sub : subResults) {
                    ans.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>dict;
        for(const auto&word:wordDict) dict[word] = true;

        return solveRE(s, dict, 0);
    }
};