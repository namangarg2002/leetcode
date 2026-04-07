class Solution {
public:
    int firstOccurence(vector<int>& nums, int target, int n){
        int s = 0;
        int e = n - 1;
        int first = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                first = mid;
                e = mid - 1;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return first;
    }
    int lastOccurence(vector<int>& nums, int target, int n){
        int s = 0;
        int e = n - 1;
        int last = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                last = mid;
                s = mid + 1;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurence(nums, target, nums.size()), lastOccurence(nums, target, nums.size())};
    }
};