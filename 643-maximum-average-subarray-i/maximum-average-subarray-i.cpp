class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0; int j=k-1;
        int sum = 0;
        for(int y=i; y<=j; y++){
            sum += nums[y];
        }
        int maxSum = sum;
        j++;
        while(j<nums.size()){
            sum -= nums[i++];
            sum += nums[j++];
            maxSum = max(maxSum, sum);
        }
        double maxAvg = maxSum/double(k);
        return maxAvg;
    }
};