class Solution {
public:
    int dikstra(int src, int n, unordered_map<int, list<pair<int, int>>>&adjList, int distanceThreshold){
        vector<int>dist(n, INT_MAX);
        set<pair<int, int>>st;
        dist[src] = 0;
        st.insert({0, src});
        int reachableCity = 0; // city at most having distanceThreshold distance
        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin());
            int nodeDist = top.first;
            int node = top.second;

            if(node != src && nodeDist <= distanceThreshold){
                reachableCity++;
            }

            for(auto child:adjList[node]){
                int currDist = nodeDist + child.second;
                if(currDist < dist[child.first]){
                    auto it = st.find({dist[child.first], child.first});
                    if(it != st.end()){
                        st.erase(it);
                    }
                    dist[child.first] = currDist;
                    st.insert({dist[child.first], child.first});
                }
            }
        }
        return reachableCity;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>>adjList;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        int city = 0;
        int minReachableCity = INT_MAX;
        for(int u=0; u<n; u++){
            int reachableCity = dikstra(u, n, adjList, distanceThreshold);
            if(reachableCity < minReachableCity){
                minReachableCity = reachableCity;
                city = u;
            }else if (reachableCity == minReachableCity) {
                city = max(city, u);
            }
        }
        return city;
    }
};