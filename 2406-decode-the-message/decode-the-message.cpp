class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        unordered_map<char, char>mp;
        for(int i=0; i<key.size(); i++){
            char ch = key[i];
            if(ch != ' ' && mp.count(ch) == 0){
                mp[ch] = start;
                start++;
            }
        }
        string ans = "";
        for(int i=0; i<message.size(); i++){
            char ch = message[i];
            if(ch != ' '){
                char decodedCode = mp[ch];
                ans.push_back(decodedCode);
            }else{
                ans.push_back(' ');
            }
        }
        return ans;
    }
};