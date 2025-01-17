class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp){
        for(int i=0; i<26; i++){
            if(temp[i] < freq2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        // step1: fill max reqired for character
        vector<int>freq2(26);
        for(auto&word: words2){
            int temp[26] = {0}; // or vector<int> temp(26, 0)

            for(auto&ch:word){
                temp[ch-'a']++;

                freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
            }
        }

        // step2: 
        for(auto&word:words1){
            vector<int> temp(26, 0);
            for(auto&ch:word){
                temp[ch-'a']++;  
            }

            if(isSubset(freq2, temp)){
                result.push_back(word);
            }
        }

        return result;
    }
};