class BrowserHistory {
    stack<string>browserStack, fwdStack;
public:
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        // let's clear all fwd history
        while(!fwdStack.empty()){
            fwdStack.pop();
        }
        browserStack.push(url);
    }
    
    string back(int steps) {
        while(steps--){
            // ek baar back jaega
            if(browserStack.size() > 1){
                fwdStack.push(browserStack.top());
                browserStack.pop();
            }else{
                // only home page is present .
                // back not possible
                break;
            }
        }
        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(fwdStack.size() > 0){
                browserStack.push(fwdStack.top());
                fwdStack.pop();
            }else{
                break;
            }
        }
        return browserStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */