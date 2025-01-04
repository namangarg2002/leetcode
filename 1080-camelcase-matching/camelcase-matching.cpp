class Solution {
    bool isMatch(const string& query, const string& pattern) {
        int i = 0;
        for (char c : query) {
            if (i < pattern.size() && c == pattern[i]) {
                i++;
            } else if (isupper(c)) {
                return false;
            }
        }
        return i == pattern.size();
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(const string&query:queries){
            result.push_back(isMatch(query, pattern));
        }        
        return result;
    }
};