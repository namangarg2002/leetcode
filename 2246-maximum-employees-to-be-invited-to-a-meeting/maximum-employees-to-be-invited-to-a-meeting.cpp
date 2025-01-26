class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0), longestChain(n, 0), cycleSize(n, 0);
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) 
            inDegree[favorite[i]]++;
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            int v = favorite[u];
            longestChain[v] = max(longestChain[v], longestChain[u] + 1);
            if (--inDegree[v] == 0)
                q.push(v);
        }
        
        int maxChain = 0, maxCycle = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int u = i, len = 0;
                while (!visited[u]) {
                    visited[u] = true;
                    u = favorite[u];
                    len++;
                }
                if (len > 1) 
                    maxCycle = max(maxCycle, len);
                for (int j = 0; j < len; ++j) {
                    cycleSize[u] = len;
                    u = favorite[u];
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (cycleSize[i] == 2) {
                int u = favorite[i];
                maxChain += 2 + longestChain[i] + longestChain[u];
                cycleSize[i] = cycleSize[u] = 0;
            }
        }
        
        return max(maxCycle, maxChain);
    }
};