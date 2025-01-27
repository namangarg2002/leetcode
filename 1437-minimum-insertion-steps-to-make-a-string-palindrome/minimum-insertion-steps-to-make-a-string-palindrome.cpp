class Solution {
public:
    int solveTabSO(string a, string b){
        vector<int>curr(b.length()+1, 0);
        vector<int>next(b.length()+1, 0);

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }else{
                    ans = 0 + max(curr[j+1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longextPalindromeSubseq(string s){
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;

        return solveTabSO(first, second);
    }
    int minInsertions(string s) {
        int ans = s.size()-longextPalindromeSubseq(s);

        return ans;
    }
};