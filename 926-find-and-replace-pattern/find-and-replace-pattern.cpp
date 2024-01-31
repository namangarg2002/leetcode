class Solution {
public:
    // this function normalizes all the words and pattern into a similar format
    // so that we can compare them find the solution
    void createMapping(string& str){
        // find Mapping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str){
            if(mapping[ch]==0){
                mapping[ch] = start;
                start++;
            }
        }
        // update the string
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // firstly normalize the pattern
        createMapping(pattern);

        // compare with all words 
        for(string s : words){

            string tempString = s;
            createMapping(tempString);
            if(tempString == pattern){
                ans.push_back(s);
            }
        }
        return ans;
    }
};