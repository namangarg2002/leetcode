class Solution {
public:
    int solveLongestIncresingSubseqOptimalBS(vector<int>&arr, vector<int>&LIS){
        if(arr.size() == 0) return 0;

        vector<int>ans;
        LIS.clear();
        LIS.push_back(1);
        ans.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
                LIS.push_back(ans.size());
            }else{
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
                LIS.push_back(index + 1);
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> LIS, LDS;
        // make LIS and ldr array by taking each element as pivot
        solveLongestIncresingSubseqOptimalBS(nums, LIS);
        reverse(nums.begin(), nums.end());
        solveLongestIncresingSubseqOptimalBS(nums, LDS);
        reverse(nums.begin(), nums.end());
        reverse(LDS.begin(), LDS.end());

        int largestMountain = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(LIS[i] == 1 || LDS[i] == 1) continue;
            largestMountain = max(largestMountain, LIS[i] + LDS[i] - 1);
        }
        int ans = nums.size()-largestMountain;
        return ans;
    }
};