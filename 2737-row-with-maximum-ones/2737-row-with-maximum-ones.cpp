class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       vector<int> ans; 
        int n = mat.size();
        // oneCount -> will store max number of 1's in a row    
        int oneCount = INT_MIN;
        //    rowNo -> will store index of max no of 1's row
        int rowNo = -1;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count > oneCount){
                oneCount = count;
                rowNo = i;
            }

        }
        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
    }
};