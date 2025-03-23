class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int rows = matrix.size();
        if(rows == 0){
            return ans;
        }
        int cols = matrix[0].size();
        int startRow = 0;
        int endRow = rows-1;
        int startCol = 0;
        int endCol = cols-1;

        int count = 0;
        int totalElement = rows*cols;
        while(count<totalElement){
            for(int i=startCol; i<=endCol && count < totalElement; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow; i<=endRow && count < totalElement; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol; i>=startCol && count < totalElement; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow; i>=startRow && count < totalElement; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};