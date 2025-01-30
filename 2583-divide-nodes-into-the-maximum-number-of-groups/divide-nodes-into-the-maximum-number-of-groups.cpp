class Solution {
public:
    // bool bfs(int node, vector<vector<int>>& graph, vector<int>& color) {
    //     queue<int> q;
    //     q.push(node);
    //     color[node] = 1; // Start with color 1
        
    //     while (!q.empty()) {
    //         int current = q.front();
    //         q.pop();
            
    //         for (int neighbor : graph[current]) {
    //             if (color[neighbor] == -1) {
    //                 color[neighbor] = 1 - color[current];
    //                 q.push(neighbor);
    //             } else if (color[neighbor] == color[current]) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    int magnificentSets(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> color(n + 1, -1);
        vector<bool> visited(n + 1, false);
        int total = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            
            queue<int> q;
            q.push(i);
            visited[i] = true;
            color[i] = 0;
            vector<int> component;
            component.push_back(i);
            bool is_bipartite = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        color[v] = color[u] ^ 1;
                        q.push(v);
                        component.push_back(v);
                    } else {
                        if (color[v] == color[u]) {
                            is_bipartite = false;
                        }
                    }
                }
            }
            
            if (!is_bipartite) {
                return -1;
            }
            
            int diameter = 0;
            for (int start : component) {
                vector<int> dist(n + 1, -1);
                queue<int> bfs_q;
                bfs_q.push(start);
                dist[start] = 0;
                int max_dist = 0;
                
                while (!bfs_q.empty()) {
                    int u = bfs_q.front();
                    bfs_q.pop();
                    
                    for (int v : adj[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            max_dist = max(max_dist, dist[v]);
                            bfs_q.push(v);
                        }
                    }
                }
                
                diameter = max(diameter, max_dist);
            }
            
            total += diameter + 1;
        }
        
        return total;
    }
};