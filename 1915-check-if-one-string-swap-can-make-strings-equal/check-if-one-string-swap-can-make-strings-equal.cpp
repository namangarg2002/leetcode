class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n = s1.size();
        int mismatch_count = 0;
        int first_mismatch_index = -1;
        int second_mismatch_index = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                mismatch_count++;
                if (mismatch_count == 1) {
                    first_mismatch_index = i;
                } else if (mismatch_count == 2) {
                    second_mismatch_index = i;
                } else {
                    return false;
                }
            }
        }

        if (mismatch_count == 2) {
            swap(s1[first_mismatch_index], s1[second_mismatch_index]);
            return s1 == s2;
        }
        return mismatch_count == 0;  
    }
};