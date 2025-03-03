class Solution {
public:
    vector<int> rowWithMaxOnes(vector<vector<int>>& mat, int row, int col){
        vector<int>result;
        int maxi = INT_MIN;
        int rowIndex = -1;
        for(int i=0; i<row; i++){
            int countOnes = 0;
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                   countOnes++; 
                }
            }
            if(countOnes > maxi){
                maxi = countOnes;
                rowIndex = i;
            }
        }
        result.push_back(rowIndex);
        result.push_back(maxi);

        return result;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        return rowWithMaxOnes(mat, row, col);
    }
};