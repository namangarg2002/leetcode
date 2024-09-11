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
                // Check if stack is empty before accessing the top
                if(st.empty()) {
                    return false;
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
        if(st.size() == 0){
            return true;
        }else{
            return false;
        }
    }
};