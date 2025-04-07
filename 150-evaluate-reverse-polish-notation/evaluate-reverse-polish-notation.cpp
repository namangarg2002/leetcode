class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto& ch: tokens){
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(ch == "+"){
                    st.push(b+a);
                }else if(ch == "-"){
                    st.push(b-a);
                }else if(ch == "*"){
                    st.push(b*a);
                }else{
                    st.push(b/a);
                }
            }else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};