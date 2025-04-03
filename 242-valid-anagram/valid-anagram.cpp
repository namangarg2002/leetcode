class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // int i = 0;
        // int j = 0;
        // while(i<s.size() || j<t.size()){
        //     if(s[i] == t[j]){
        //         i++;
        //         j++;
        //     }else{
        //         return false;
        //     }
        // }

        return (s==t) ? true : false;
    }
};