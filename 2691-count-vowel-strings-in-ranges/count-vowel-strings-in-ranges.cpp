class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }else{
            return false;
        }
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size();
        int W = words.size();

        vector<int> result(Q);
        vector<int>csum(W);
        int sum = 0;
        for(int i=0; i<W; i++){
            if(isVowel(words[i].back()) && isVowel(words[i].front())){// kya yeah vowel hai
                sum++;
            }
            csum[i] = sum;
        }
        // at that step we find the cumelative sum of each words accoding to isvowel function 
        for(int i=0; i<Q; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            int output = csum[r] - (l > 0 ? csum[l-1] : 0);
            result[i] = output;
        }
        return result;
    }
};