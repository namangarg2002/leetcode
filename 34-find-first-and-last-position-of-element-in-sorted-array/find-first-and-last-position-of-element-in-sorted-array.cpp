class Solution {
public:
    int firstOccurence(vector<int>& nums, int n, int target){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid] == target){
                ans = mid;
                e = mid - 1;
            }else if(target > nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2; 
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums, int n, int target){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid] == target){
                ans = mid;
                s = mid + 1;
            }else if(target > nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        int firstPositionIndex = firstOccurence(nums, n, target);
        int lastPositionIndex = lastOccurence(nums, n, target);

        ans.push_back(firstPositionIndex);
        ans.push_back(lastPositionIndex);

        return ans;
        
    }
};