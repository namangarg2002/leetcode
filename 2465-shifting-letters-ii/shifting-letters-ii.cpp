class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            diff[start] += (direction == 1) ? 1 : -1;
            diff[end + 1] += (direction == 1) ? -1 : 1;
        }

        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += diff[i];
            int shiftValue = (s[i] - 'a' + netShift) % 26;
            if (shiftValue < 0) shiftValue += 26; 
            s[i] = 'a' + shiftValue;
        }

        return s;
            
    }
};