class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                // ch is digit;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string str = "";
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            str.push_back(top);
        }
        reverse(str.begin(), str.end());

        return str;
    }
};