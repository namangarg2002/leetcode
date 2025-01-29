class Solution {
public:
    int solveRE(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];

        // diff = P1 - P2;
        int diffByStart = nums[start] - solveRE(nums, start+1, end);
        int diffByEnd = nums[end] - solveRE(nums, start, end-1);

        return max(diffByStart, diffByEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        int ans = solveRE(nums, 0, nums.size()-1);

        return (ans >=0) ? true: false;
    }
};