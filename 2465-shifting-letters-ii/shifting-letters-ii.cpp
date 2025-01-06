class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       int n = s.length();

       vector<int> diff(n, 0);
        // Step1: Build the diff array
        for(auto &query : shifts){
            int L = query[0];
            int R = query[1];
            int dir = (query[2]== 0)? -1 : 1;

            diff[L] += dir;
            if(R+1 < n){
                diff[R+1] -= dir;
            }

        }
        // Step2 : Find cummulative sum to find the resultant chnage/shift in the index i
        for(int i=1; i<n; i++){
            diff[i] += diff[i-1];
        }
        
        // Now apply the shift/change
        for(int i=0; i<n; i++){
            int shift = diff[i] % 26; // handeling out of range
            if(shift < 0){
                shift += 26; // warap around
            }
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }

        return s;

            
    }
};