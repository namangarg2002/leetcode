class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                // for open brackets-> just push
                st.push(ch);
            }else{
                if(st.empty()) {
                    return false; // Closing bracket with no matching opening bracket
                }
                // closing bracket
                if((ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[')){
                    // matched
                    st.pop();
                }else {
                    return false;
                }

            }
        }
        return st.empty();
    }
};