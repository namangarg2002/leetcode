class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        
        int count = 0;
        int ops = 0; 
        for (int i = 0; i < n; ++i) {
            result[i] += ops; 
            if (boxes[i] == '1') {
                count++;
            }
            ops += count;
        }
        
        count = 0;
        ops = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += ops;  // Add operations from the right
            if (boxes[i] == '1') {
                count++;  // Increment ball count
            }
            ops += count;  // Update cumulative operations
        }
        return result;
    }
};