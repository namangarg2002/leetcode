class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){

                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                else if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[row-1][col-1];
    }
};