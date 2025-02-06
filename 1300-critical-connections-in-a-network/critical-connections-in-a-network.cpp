class Solution {
public:
    void solve(int src, int parent, unordered_map<int, list<int>>&adjList, int &timer, vector<vector<int>>& ans, vector<int> &low, vector<int> &tin, vector<bool> &visit){
        visit[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
        // nbr
        for(auto nbr:adjList[src]){
            if(nbr == parent){
                // ignore this
                continue;
            }
            if(!visit[nbr]){
                // steep 1:
                solve(nbr, src, adjList, timer, ans, low, tin, visit);
                // low update
                low[src] = min(low[src], low[nbr]);
                // bridge Testing
                if(low[nbr]>tin[src]){
                    ans.push_back({nbr, src});
                }

            }else{
                // ek or rasta mil gaya
                // low ko updat ekar do
                low[src] = min(low[src], low[nbr]);
                // no need of bridge testing

            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>>adjList;
        for(auto vec:connections){
            int u = vec[0];
            int v = vec[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // main logic
        int timer = 0;
        vector<vector<int>>ans;
        vector<int> low(n, -1);
        vector<int> tin(n, -1);
        int src = 0;
        int parent = -1;
        vector<bool> visit(n, false);
        solve(src, parent, adjList, timer, ans, low, tin, visit);

        return ans;
    }
};