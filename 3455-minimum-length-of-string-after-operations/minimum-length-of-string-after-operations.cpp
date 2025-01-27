class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int>mp;
        for(const auto&ch:s){
            mp[ch]++;
        }
        int count = 0;
        for(const auto&pair:mp){
            if(pair.second & 1){
                // odd case
                count += 1;
            }else{
                count += 2;
            }
        }

        return count;
    }
};