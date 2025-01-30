class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>>q;
        int fresh = 0; 
        int time = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        } 

        if (fresh == 0) return 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;
            for(int i=0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();

                for(auto [dr, dc]: directions){
                    int nr = r + dr, nc = c + dc;

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotten = true;
                    }
                }
            }
            if (rotten) time++;
        }
        if(fresh > 0) return -1;
        return time;
    }
};