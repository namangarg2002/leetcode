class Solution {
public:
    vector<int> parent, rank;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // Cycle detected

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initialize DSU
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!unionSet(u, v)) {
                return edge; // Redundant edge found
            }
        }
        
        return {};
    }
};