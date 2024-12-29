class Solution {
public:
    struct mycomp{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA > distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, int>, vector<pair<int,int>>, mycomp>pq; //minHeap based on gining higher priority to point cloder to origin.
        for(auto p:points){
            pq.push({p[0],p[1]});
        }while(!pq.empty() && k--){
            auto&top = pq.top();
            ans.push_back({top.first, top.second});
            pq.pop();
        }
        return ans;
    }
};