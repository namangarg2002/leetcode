class Solution {
public:
    int findPivotIndex(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }

            if (nums[s] > nums[mid]) {
                e = mid - 1; 
            } else {
                s = mid + 1;  
            }
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // M1:
        vector<pair<int, int>>vec;
        for(int i=0; i<n; i++){
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(vec[mid].first == target){
                return vec[mid].second;
            }else if(vec[mid].first < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;

        // if (n == 0) return -1;
        
        // int pivotIndex = findPivotIndex(nums);

        // if (pivotIndex == -1) {
        //     return binarySearch(nums, 0, n - 1, target);
        // }

        // if (target >= nums[0] && target <= nums[pivotIndex]) {
        //     return binarySearch(nums, 0, pivotIndex, target);
        // } else {
        //     return binarySearch(nums, pivotIndex + 1, n - 1, target);
        // }
    }
};