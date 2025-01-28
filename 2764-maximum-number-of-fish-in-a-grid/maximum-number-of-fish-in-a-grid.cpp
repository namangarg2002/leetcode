class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0; // Out of bounds or already visited
        }
        
        int fishCount = grid[i][j]; // Collect fish from the current cell
        grid[i][j] = 0; // Mark the cell as visited by setting it to 0
        
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            fishCount += dfs(grid, i + dx[k], j + dy[k]);
        }
        
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) { // If the cell contains fish
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }
        
        return maxFish;
    }
};