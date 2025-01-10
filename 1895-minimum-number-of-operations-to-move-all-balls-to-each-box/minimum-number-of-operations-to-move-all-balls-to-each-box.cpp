class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        
        int cumValue = 0;
        int cumValueSum = 0;
        // find moves for all left balls to index
        for(int i=0; i<n; i++){
            result[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }
        int cumValue1 = 0;
        int cumValueSum1 = 0;
        for(int i=n-1; i>=0; i--){
            result[i] += cumValueSum1;
            cumValue1 += boxes[i] == '0' ? 0 : 1;
            cumValueSum1 += cumValue1;
        }
        return result;
    }
};