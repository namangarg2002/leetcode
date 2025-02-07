class Solution {
public:
    bool dfs(int src, vector<bool>& visit, unordered_map<int, vector<int>>& adj){
        visit[src] = true;
        for(auto child: adj[src]){
            if(!visit[child]){
                dfs(child, visit, adj);
            }
        }
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n -1){
            return -1;
        }
        unordered_map<int, vector<int>> adj;
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        int ans = 0;
        vector<bool> visit(n, false);
        for(int i=0; i<n; i++){
            if(!visit[i]){
                ans++;
                dfs(i, visit, adj);
            }
        }
        return ans-1;
    }
};