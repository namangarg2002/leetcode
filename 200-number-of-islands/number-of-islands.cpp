class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>>& grid, map<pair<int,int>, bool> &visit){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY]=='1' && visit[{newX, newY}] == false){
            return true;
        }else{
            return false;
        }
    }
    void bfs(int srcX, int srcY, vector<vector<char>>& grid, map<pair<int,int>, bool> &visit){
        queue<pair<int, int>>q;
        // initial State
        q.push({srcX, srcY});
        visit[{srcX, srcY}] = true;
        while(!q.empty()){
            pair<int,int> frontNodePair = q.front();
            q.pop();
            int tempX = frontNodePair.first;
            int tempY = frontNodePair.second;

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX, newY, grid, visit)){
                    q.push({newX, newY});
                    visit[{newX, newY}] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // queue<pair<int, int>>q;
        map<pair<int,int>, bool> visit;
        int count = 0;
        // har node ke liye loop laga dia 
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visit[{i,j}] && grid[i][j] == '1'){
                    bfs(i, j, grid, visit);
                    count++;
                }
            }
        }
        return count;
    }
};