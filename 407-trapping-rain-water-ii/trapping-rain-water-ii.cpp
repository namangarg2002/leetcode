class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
       int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0; // No water can be trapped if the grid is too small.

        // Min-heap to store the boundary cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Visited array to track visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the min-heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int waterTrapped = 0;

        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();

            int x = cell.first;
            int y = cell.second;

            for (const auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Check if the new cell is within bounds and not visited
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    // Calculate water trapped at this cell
                    waterTrapped += max(0, height - heightMap[nx][ny]);

                    // Add the cell to the heap with the max height between the current cell and the neighbor
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return waterTrapped; 
    }
};