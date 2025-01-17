class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n & 1){
            // odd
            return false;
        }
        if(s.front() == ')' && locked.front()==1){
            return false;
        }
        if(s.back() == '(' && locked.back()==1){
            return false;
        }

        stack<int>open;
        stack<int>openClose;

        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                openClose.push(i);
            }else{
                if(s[i] == '('){
                    open.push(i);
                }
                if(s[i] == ')'){
                    if(!open.empty()){
                        open.pop();
                    }else if(!openClose.empty()){
                        openClose.pop();
                    }else{
                        return false;
                    }
                }

            }
        }
        while(!open.empty() && !openClose.empty() && open.top()< openClose.top()){
            open.pop();
            openClose.pop();
        }

        return (open.empty()) ? true : false;

    }
};