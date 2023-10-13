class Solution {
public:
int bruteForce(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        int lsum=0;
        int rsum=0;

        // left sum excluding current index

        for(int j=0; j<i; j++){
            lsum += nums[j];
        }
        for(int j=i+1; j<nums.size(); j++){
            rsum += nums[j];
        }
        if(lsum==rsum){
            return i;
        }
    }
    return -1;
}
    int pivotIndex(vector<int>& nums) {
        int ans = bruteForce(nums);
        return ans;
    }
};