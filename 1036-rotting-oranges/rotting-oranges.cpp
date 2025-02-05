class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<int>>&temp){
        if(newX>=0 && newY>=0 && newX<temp.size() && newY<temp[0].size() && temp[newX][newY]==1){
            return true;
        }else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // pair<int, int>, int> ->{coordinates, time}
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>temp = grid;
        int minTime = 0;

        // find all rotten oranges an dput themin a queue
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    //every src node ka time 0 set kar rhe hai
                    q.push({{i, j}, minTime});
                }
            }
        }
        // bsf Logic
        while(!q.empty()){
            pair<pair<int, int>, int> TopNodePair = q.front();
            q.pop();
            pair<int,int> frontNodeCoordinate = TopNodePair.first;
            int srcX = frontNodeCoordinate.first;
            int srcY = frontNodeCoordinate.second;
            int frontNodeTime = TopNodePair.second;

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i=0; i<4; i++){
                int newX = srcX + dx[i];
                int newY = srcY + dy[i];
                if(isSafe(newX, newY, temp)){
                    q.push({{newX, newY}, frontNodeTime+1});
                    minTime = max(minTime, frontNodeTime+1);
                    // mark this node as rotten
                    temp[newX][newY] = 2;
                }
            }
        }
        // yaha tk apne jitne oranges rotten akrne the utne kar liye hai
        // now i want to check is we rotten all oranges rotten or not 
        int freshOrangeCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==1){
                    freshOrangeCount++;
                }
            }
        }
        if(freshOrangeCount != 0){
            return -1;
        }else{
            return minTime;
        }

    }
};