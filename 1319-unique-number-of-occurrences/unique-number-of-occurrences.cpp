class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        unordered_set<int>seen;
        for(auto&num:arr){
            mp[num]++;
        }
        for(auto&it: mp){
            if(seen.find(it.second) != seen.end()){
                return false;
            }
            seen.insert(it.second);
        }
        return true;
    }
};