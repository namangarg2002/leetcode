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
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1, vector<int>(2, 0));

        for(int i=nums1.size()-1; i>=1; i--){
            for(int isSwap=1; isSwap>=0; isSwap--){
                int prev1 = nums1[i-1], prev2 = nums2[i-1];
                if(isSwap){
                    swap(prev1, prev2);
                }
                int swap = INT_MAX, noswap = INT_MAX;
                if(prev1 < nums2[i] && prev2 < nums1[i]){
                    swap = 1 + dp[i+1][1];
                }
                if(prev1 < nums1[i] && prev2 < nums2[i]){
                    noswap = 0 + dp[i+1][0];
                }
                dp[i][isSwap] = min(swap, noswap);
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // // recursive Approach
        // return solveRE(nums1, nums2, 0, -1, -1);

        // // Memoiation Approach
        // vector<vector<int>>dp(nums1.size(), vector<int>(2, -1));
        // return solveMem(nums1, nums2, 0, -1, -1, dp, 0);

        // tabulation Approach
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveTab(nums1, nums2);
    }
};