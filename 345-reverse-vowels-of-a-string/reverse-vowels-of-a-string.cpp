class Solution {
public:
    bool is_vowel(char c) {

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l = 0;
        int h = s.size()-1;
        while(l<h){
            if(is_vowel(s[l]) && is_vowel(s[h])){
                swap(s[l], s[h]);
                    l++;
                    h--;
            }else if(!is_vowel(s[l])){
                l++;
            }else{
                h--;
            }
        }
        return s;
    }
};