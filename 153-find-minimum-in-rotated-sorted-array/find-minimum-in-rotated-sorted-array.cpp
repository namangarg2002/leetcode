class Solution {
public:
    int findMin(vector<int>& nums) {
        // M1:
        // sort(nums.begin(), nums.end());
        // return nums[0];

        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        while(s < e){
            if(nums[mid] > nums[e]){
                s = mid + 1;
            }else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return nums[s];
    }
};