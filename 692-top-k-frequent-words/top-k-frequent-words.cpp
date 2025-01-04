class Solution {
public:
    struct compare{
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            if(a.first == b.first){
                return a.second > b.second; // Lexicographical order for same frequency
            }
            return a.first < b.first; // Higher frequency has priority(max heap)
        }

    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        // M1: using hashing and priority_queue
        vector<string> ans;
        // Step1: finding frequencies of each word
        unordered_map<string, int> map;
        for(auto i:words){
            map[i]++;
        }

        // Step2: priority_queue for top K elements
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare>pq;

        for(auto item: map){
            pq.push({item.second, item.first}); // at this step the higher frequency element gets its priority
        }

        while(!pq.empty() && k--){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};