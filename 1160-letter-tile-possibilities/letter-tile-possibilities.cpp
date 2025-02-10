class Solution {
public:
    int solve(vector<int>&freq){
        int ans = 0;
        // har ek dabbe me, A->Z tk insert karne ka try karrha hu
        for(int i=0; i<26; i++){
            // charctwr exist karta  h ki nhi
            if(freq[i] != 0){
                // ek answer yaha senikal gaya
                freq[i]--;
                ans++;
                // baki recursssion sambhal lega
                int recurssionKaAnswer = solve(freq);
                ans += recurssionKaAnswer;
                // backTracking logic
                freq[i]++;
            }
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26, 0);
        // count freq of character
        for(auto ch: tiles){
            freq[ch-'A']++;
        }
        int ans = solve(freq);
        return ans;

    }
};