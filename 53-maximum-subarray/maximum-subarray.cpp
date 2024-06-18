class Solution {
public:
    int maxSumArrayHelper(vector<int>&v, int start, int end){
        if(start == end) return v[start];
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + ((end - start) >> 1);

        int maxLeftSum = maxSumArrayHelper(v, start, mid);
        int maxRightSum = maxSumArrayHelper(v, mid+1, end);

        // Max Cross Border Sum.
        int leftBorderSum = 0, rightBorderSum = 0;
        // left Border sum
        for(int i = mid; i>=start; i--){
            leftBorderSum += v[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }
        // Right Border sum
        for(int i = mid+1; i<=end; i++){
            rightBorderSum += v[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(crossBorderSum, max(maxLeftSum, maxRightSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums, 0, nums.size()-1);
    }
};