class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char>letters;
        for(int i=0; i<n; i++){
            letters.insert(s[i]);
        }
        int result = 0;

        for(char letter:letters){
            // letter - 'a'
            int leftMostIndex = -1;
            int rightMostIndex = -1;

            for(int i=0; i<n; i++){
                if(s[i] == letter){
                    if(leftMostIndex == -1){
                        leftMostIndex = i;
                    }

                    rightMostIndex = i;
                }
            }
            unordered_set<char>st;
            for(int i = leftMostIndex+1; i<rightMostIndex; i++){
                st.insert(s[i]);
            }
            result += st.size();
        }
        return result;
    }
};