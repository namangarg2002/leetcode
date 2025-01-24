class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);
        queue<int> q;
        vector<int> safeNodes;

        // Build reverse graph and calculate out-degrees
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outDegree[i] = graph[i].size();
        }

        // Add nodes with 0 out-degree to the queue
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes with 0 out-degree
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Sort safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};