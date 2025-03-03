class Solution {
public:
    vector<vector<int>> transposedMatrix(vector<vector<int>>& matrix, int row, int col){
        vector<vector<int>> result(col, vector<int>(row));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        return transposedMatrix(matrix, row, col);

    }
};