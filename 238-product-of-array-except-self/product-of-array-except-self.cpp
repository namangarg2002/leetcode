class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> LTRProduct(n);
        vector<int> RTLProduct(n);

        vector<int>ans;

        LTRProduct[0] = 1;
        RTLProduct[n-1] = 1;

        for(int i=1; i<n; i++){
            LTRProduct[i] = LTRProduct[i-1]*nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            RTLProduct[i] = RTLProduct[i+1]*nums[i+1];
        }

        for(int i=0; i<n; i++){
            int product = LTRProduct[i]*RTLProduct[i];
            ans.push_back(product);
        }
        return ans;
    }
};