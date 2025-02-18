class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>>temp;
        for(int i=0; i<nums.size(); i++){
            int index = i;
            int value = nums[i];
            temp.push_back({value, i});
        }
        // ṣort basis on value
        sort(temp.begin(), temp.end());
        // logic
        int s = 0; 
        int e = nums.size()-1;
        int sum = 0;
        vector<int>ans;
        while(s < e){
            sum = temp[s].first + temp[e].first;

            if(sum == target){
                ans.push_back(temp[s].second);
                ans.push_back(temp[e].second);
            }
            if(sum < target){
                s++;
            }else{
                e--;
            }
        }
        return ans;
    }
};