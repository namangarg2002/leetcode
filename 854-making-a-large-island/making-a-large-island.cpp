class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int islandId) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = islandId; // Mark the cell with the island ID
        int size = 1;
        size += dfs(grid, i+1, j, islandId);
        size += dfs(grid, i-1, j, islandId);
        size += dfs(grid, i, j+1, islandId);
        size += dfs(grid, i, j-1, islandId);
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandId = 2; // Start from 2 to avoid conflict with 0 and 1
        unordered_map<int, int> islandSizes; // Maps island ID to its size
        
        // Step 1: Assign unique IDs to each island and calculate their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    islandId++;
                }
            }
        }
        
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    // Collect unique neighboring island IDs
                    unordered_set<int> neighbors;
                    if (i > 0 && grid[i-1][j] != 0) neighbors.insert(grid[i-1][j]);
                    if (i < n-1 && grid[i+1][j] != 0) neighbors.insert(grid[i+1][j]);
                    if (j > 0 && grid[i][j-1] != 0) neighbors.insert(grid[i][j-1]);
                    if (j < n-1 && grid[i][j+1] != 0) neighbors.insert(grid[i][j+1]);
                    
                    int newSize = 1; // The current cell being changed to 1
                    for (int neighborId : neighbors) {
                        newSize += islandSizes[neighborId];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }
        
        return maxSize == 0 ? n * n : maxSize;
    }
};