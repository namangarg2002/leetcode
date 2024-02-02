class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q{{1,2,3,4,5,6,7,8,9}};

        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num>high){
                return ans;
            }
            if(low<=num && num<=high){
                ans.push_back(num);
            }
            int lastdigit = num%10;
            if(lastdigit<9){
                q.push(num*10 + lastdigit+1);
            }
        }
        return ans;
    }
};