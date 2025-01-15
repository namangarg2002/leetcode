class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto &word: words){
            int m = pref.length();
            if(word.substr(0, m)==pref){
                count++;
            }
        }
        return count;
    }
};