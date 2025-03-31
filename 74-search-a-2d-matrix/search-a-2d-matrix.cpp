class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = rows*cols-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            int rowIndex = mid/cols;
            int colIndex = mid%cols;
            int currElement = matrix[rowIndex][colIndex];

            if(currElement == target){
                return true;
            }else if(currElement > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};