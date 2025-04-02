class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;
        int length = s.length();
        while(index<length){
            if(ans.empty() || ans.back() != s[index]){
                ans.push_back(s[index]);
            }else{
                ans.pop_back();
            }
            index++;
        }
        return ans;
    }
};