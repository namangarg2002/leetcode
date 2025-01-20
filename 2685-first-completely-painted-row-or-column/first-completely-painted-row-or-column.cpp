class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                position[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        
        for (int k = 0; k < arr.size(); ++k) {
            int num = arr[k];
            auto [r, c] = position[num];
            rowCount[r]++;
            colCount[c]++;
            
            if (rowCount[r] == cols || colCount[c] == rows) {
                return k; 
            }
        }
        
        return -1;
    }
};