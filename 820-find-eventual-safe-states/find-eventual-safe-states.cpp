class Solution {
public:
    bool dfs(int src, unordered_map<int, bool>&visit, unordered_map<int, bool>&dfsTrack, vector<vector<int>>& graph){
        visit[src] = true;
        dfsTrack[src] = true;
        for(auto child:graph[src]){
            if(!visit[child]){
                if(dfs(child, visit, dfsTrack, graph)){
                    return true;
                }
            }else{
                if(visit[child]==true && dfsTrack[child]==true){
                    return true;
                }
            }
        }
        dfsTrack[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        unordered_map<int, bool>visit;
        unordered_map<int, bool>dfsTrack;
        for(int i=0; i<n; i++){
            if(!visit[i]){
                dfs(i, visit, dfsTrack, graph);
            }
        }
        for(int i=0; i<n; i++){
            if(!dfsTrack[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};