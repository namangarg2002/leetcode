class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // M1: using vector
    //     vector<pair<int, int>>temp;
    //     vector<int>ans;
    //     for(int i=0; i<nums.size(); i++){
    //         int value = nums[i];
    //         int index = i;
    //         temp.push_back({value, index});
    //     }

    //     // sort on basis of value
    //     sort(temp.begin(), temp.end());
    //     int s = 0; 
    //     int e = temp.size()-1;
    //     while(s<e){
    //         int sum = temp[s].first + temp[e].first;

    //         if(sum==target){
    //             ans.push_back(temp[e].second);
    //             ans.push_back(temp[s].second);
    //             return ans;
    //         }
    //         if(sum>target){
    //             e--;
    //         }else{
    //             s++;
    //         }
    //     }

    //     return ans;

        // M2: using unordered_map
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }

        return {};

    }
};