class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>>q;

        int count=0;
        vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(auto [dx, dy]: directions){
                            int newX = dx + x;
                            int newY = dy + y;

                            if(newX >=0 && newX < row && newY >=0 && newY < col && grid[newX][newY] == '1'){
                                q.push({newX, newY});
                                grid[newX][newY] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};