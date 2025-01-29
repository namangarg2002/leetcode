class Solution {
public:
    int solveRE(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2){
        if(i==nums1.size()) return 0; // since num1 and num2 are same size so no need to check for num2 also

        int swap = INT_MAX, noswap = INT_MAX;
        // swap Condition
        if(prev1 < nums2[i] && prev2 < nums1[i]){
            swap = 1 + solveRE(nums1, nums2, i+1, nums2[i], nums1[i]);
        }
        // noswap condition
        if(prev1 < nums1[i] && prev2 < nums2[i]){
            noswap = 0 + solveRE(nums1, nums2, i+1, nums1[i], nums2[i]);
        }
        return min(swap, noswap);
    }
    int solveMem(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2, vector<vector<int>>&dp, int isSwap){
        if(i==nums1.size()) return 0;

        if(dp[i][isSwap] != -1) return dp[i][isSwap];

        int swap = INT_MAX, noswap = INT_MAX;
        if(prev1 < nums2[i] && prev2 < nums1[i]){
            swap = 1 + solveMem(nums1, nums2, i+1, nums2[i], nums1[i], dp, 1);
        }
        if(prev1 < nums1[i] && prev2 < nums2[i]){
            noswap = 0 + solveMem(nums1, nums2, i+1, nums1[i], nums2[i], dp, 0);
        }
        dp[i][isSwap] = min(swap, noswap);
        return dp[i][isSwap];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // // recursive Approach
        // return solveRE(nums1, nums2, 0, -1, -1);

        // Memoiation Approach
        vector<vector<int>>dp(nums1.size(), vector<int>(2, -1));
        return solveMem(nums1, nums2, 0, -1, -1, dp, 0);
    }
};