class Solution {
public:
    struct Info{
        int data;
        int rowIndex;
        int colIndex;

        Info(int val, int rIndex, int cIndex) : data(val), rowIndex(rIndex), colIndex(cIndex) {};
    };
    struct compare{
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
        } 
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info* ,vector<Info* >, compare>pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        // process first k element
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            int row = i;
            int col = 0;

            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            Info* topNode = pq.top();
            pq.pop();

            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;

            mini = topNode->data;
            // maxi ki value pahle se padi hai
            // compare krlete hai for smaller range
            if((maxi-mini) < (ansEnd-ansStart)){
                // update ans;
                ansStart = mini;
                ansEnd = maxi;
            }

            // insert wala step
            if(topCol + 1 < nums[topRow].size()){
                int newElement = nums[topRow][topCol+1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo);
            } 
            else{
                // aagee koi eleemnt ni h push karn ko
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};