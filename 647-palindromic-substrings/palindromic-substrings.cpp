class Solution {
public:
    int check(string s, int start, int end){
        int count = 0;
        while(start>=0 && end<s.length() && s[start] == s[end]){
            count++;
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
      int totalCount = 0;
      for(int index=0; index<s.length(); index++){
        totalCount += check(s, index, index);
        totalCount += check(s, index, index+1);

      }
      return  totalCount;
    }
};