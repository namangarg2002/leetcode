class Solution {
public:
    struct Variable{
        char name;
        int value;
        Variable(char n, int v): name(n), value(v) {}
    };
    struct compare{
        bool operator()(Variable a, Variable b) {
            return a.value < b.value;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        priority_queue<Variable, vector<Variable>, compare>maxHeap;
        if(a>0){
            Variable temp('a', a);
            maxHeap.push(temp);
        }
        if(b>0){
            Variable temp('b', b);
            maxHeap.push(temp);
        }
        if(c>0){
            Variable temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1){
            Variable first = maxHeap.top();
            maxHeap.pop();

            Variable second = maxHeap.top();
            maxHeap.pop();

            if(first.value >= 2){
                ans.push_back(first.name);
                ans.push_back(first.name);
                first.value -= 2;
            }else{
                ans.push_back(first.name);
                first.value--;
            }

            if(second.value >= 2 && second.value >= first.value){
                ans.push_back(second.name);
                ans.push_back(second.name);
                second.value -= 2;
            }else{
                ans.push_back(second.name);
                second.value--;
            }

            if(first.value > 0){
                maxHeap.push(first);
            }
            if(second.value > 0){
                maxHeap.push(second);
            }
            
        }
        if(maxHeap.size() == 1){
            Variable last = maxHeap.top();
            maxHeap.pop();
            
            if(last.value >=2){
                ans.push_back(last.name);
                ans.push_back(last.name);
                last.value -= 2;
            }else{
                ans.push_back(last.name);
                last.value--;
            }
        }
        return ans;
    }
};