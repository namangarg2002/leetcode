class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x);
    }
    
    int pop() {
        int popedElement = -1;
        if(!s2.empty()){
            popedElement = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            popedElement = s2.top();
        }
        s2.pop();
        return popedElement;
    }
    
    int peek() {
        int frontElement = -1;
        if(!s2.empty()){
            frontElement = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            frontElement = s2.top();
        }
        return frontElement;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */