class Solution {
public:
    void TopoSortBFS(int n, vector<int>&topoOrder, unordered_map<int, list<int>>&adjList){
        queue<int>q;
        map<int, int>inDegree;
        for(auto i:adjList){
            for(auto child:i.second){
                inDegree[child]++;
            }
        }
        for(int node=0; node<n; node++){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);
            for(auto child:adjList[frontNode]){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    q.push(child);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>adjList;
        vector<int>topoOrder;
        for(auto i:prerequisites){
            int u = i[1];
            int v = i[0];
            adjList[u].push_back(v);
        }
        TopoSortBFS(numCourses, topoOrder, adjList);
        // valid
        if(topoOrder.size() == numCourses){
            return topoOrder;
        }else{
            return {};
        }
    }
};