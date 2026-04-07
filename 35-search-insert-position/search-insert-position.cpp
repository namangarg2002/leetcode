class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int h = n-1;

        while(s<=h){
            int mid = s + (h-s)/2;
            if(nums[mid] == target){
                return mid;
            }else if(target > nums[mid]){
                s = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return s;
    }
};