class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() == k){
            return true;
        }
        if(s.length() < k){
            return false;
        }

        vector<int>vec(26, 0);
        for(auto&ch:s){
            vec[ch-'a']++;
        }

        int oddCount = 0;
        for(int i=0; i<26; i++){
            if(vec[i] & 1){
                oddCount++;
            }
        }

        return (oddCount <= k) ? true : false;
    }
};