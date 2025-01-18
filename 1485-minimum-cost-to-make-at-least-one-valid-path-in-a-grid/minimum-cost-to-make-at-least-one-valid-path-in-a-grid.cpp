class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions: right, left, down, up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Costs to reach each cell, initialize to INT_MAX
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                int newCost = cost[x][y] + (grid[x][y] == i + 1 ? 0 : 1);

                // Check if the new cell is within bounds and offers a lower cost
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (grid[x][y] == i + 1) {
                        dq.push_front({nx, ny}); // No cost, high priority
                    } else {
                        dq.push_back({nx, ny}); // Add cost, low priority
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};