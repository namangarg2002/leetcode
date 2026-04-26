class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int s = 0;
        int e = col - 1;

        while(s<=e){
            int mid = s + (e-s)/2;
            int maxElement = mat[0][mid];
            int maxElementIndex = 0;
            for(int i=1; i<row; i++){
                if(mat[i][mid] > maxElement){
                    maxElement = mat[i][mid];
                    maxElementIndex = i;
                }
            }

            int left = (mid - 1 >= 0) ? mat[maxElementIndex][mid-1] : -1;
            int right = (mid + 1 < col) ? mat[maxElementIndex][mid+1] : -1;

            if(maxElement > left && maxElement > right){
                return {maxElementIndex, mid};
            }else{
                if(maxElement <= left){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            
        }
        return {-1, -1};
    }
};