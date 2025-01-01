class Solution {
public:
    struct Info{
        char val;
        int count;
        Info(char ch, int cnt) : val{ch}, count{cnt} {}
    };
    struct compare{
        bool operator()(Info* a, Info* b){
            return a->count < b->count;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        // int freq[26] = {0};

        // count freq of all character in string
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch]++;
        }
        // push all character in maxHeap
        priority_queue<Info*, vector<Info*>, compare>maxHeap;
        // push all chaacter into heap, where freq > 0
        for(char i='a'; i<='z'; i++){
            if(freq[i] > 0){
              Info* temp = new Info(i, freq[i]);
              maxHeap.push(temp);
            }
        }
        string ans = "";
        // loop traverse until each character count==1
        while(maxHeap.size() > 1){
            Info* top1 = maxHeap.top();
            maxHeap.pop();
            Info* top2 = maxHeap.top();
            maxHeap.pop();

            ans.push_back(top1->val);
            top1->count--;
            ans.push_back(top2->val);
            top2->count--;

            if(top1->count > 0){
                maxHeap.push(top1);
            }else{
                delete top1;
            }
            if(top2->count > 0){
                maxHeap.push(top2);
            }else{
                delete top2;
            }
        }
        // at this stage all character count must be 1
        if(maxHeap.size() == 1){
            Info* top = maxHeap.top();
            maxHeap.pop();

            top->count--;

            if(top->count != 0){
                // answer not possible
                delete top;
                return "";
            }
            ans.push_back(top->val);
            delete top;
        }
        return ans;
    }
};