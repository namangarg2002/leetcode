class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // for(int i=0; i<nums.size(); i++){
        //     int lsum = 0;
        //     int rsum = 0;
        //     for(int j=0; j<i; j++){
        //         lsum += nums[j];
        //     }
        //     for(int j=i+1; j<nums.size(); j++){
        //         rsum += nums[j];
        //     }

        //     if(lsum==rsum){
        //         return i;
        //     }
        // }
        // return -1;

        // optimised Approach
        int n = nums.size();
        vector<int>lsum(n),rsum(n);

        lsum[0] = 0;
        rsum[n-1] = 0;

        for(int i=1; i<n; i++){
            lsum[i] = lsum[i-1] + nums[i-1];
        }
        for(int i=n-2; i>=0; i--){
            rsum[i] = rsum[i+1] + nums[i+1];
        }

        for(int i=0; i<n; i++){
            if(lsum[i]==rsum[i]){
                return i;
            }
        }
        return -1;

    }
};