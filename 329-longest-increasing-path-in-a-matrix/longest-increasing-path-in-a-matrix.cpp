class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int maxLength = 1;
        for(auto dir : direction){
            int x = i + dir[0];
            int y = j + dir[1];
            
            if( x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[i][j] < matrix[x][y]){
                int length = 1 + dfs(matrix, dp, x, y);
                maxLength = max(length, maxLength);
            }

        }
        return dp[i][j] = maxLength;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int row = matrix.size();
      int col = matrix[0].size();

      vector<vector<int>> dp(row, vector<int>(col, -1));

      int result = 0;
      for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            result = max(result, dfs(matrix, dp, i, j));
        }
      }
      return result;
    }
};