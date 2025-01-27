class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(const auto&ch:s){
            freq[ch - 'a']++;
        }
        
        int count = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] % 2 == 0  && freq[i] > 0) {
                // odd case
                count += 2;
            }else if (freq[i] % 2 == 1){
                count += 1;
            }
        }
        return count;
    }
};