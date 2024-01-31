class Solution {
public:
    string decodeMessage(string key, string message) {
        // create Mapping
        char start = 'a';
        char mapping[280] = {0};
        for(auto ch: key){
            if(ch!=' ' && mapping[ch]==0){
                mapping[ch] = start;
                start++;
            }
        }

        // use Mapping
        string ans;

        for(int i=0; i<message.length(); i++){
            char ch = message[i];
            if(ch!=' '){
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }else{
                ans.push_back(' ');
            }
        }
        return ans;

    }
};