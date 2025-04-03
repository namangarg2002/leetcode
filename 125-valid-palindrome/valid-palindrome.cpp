class Solution {
public:
    bool isPalindrome(string s) {
        string tempStr = "";
        for(auto& ch: s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) {
                tempStr.push_back(tolower(ch));
            }
        }

        int i = 0;
        int j = tempStr.length()-1;
        while(i<=j){
            if(tempStr[i] == tempStr[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }


        return true;
    }
};