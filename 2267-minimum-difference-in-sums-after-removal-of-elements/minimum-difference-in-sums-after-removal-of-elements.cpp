class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<ll>prefix(nums.size(), -1), suffix(nums.size(), -1);

        // prefix[i] = sum of first n elements from left side.
        // prefix[i] = sum of first n elements from right side.

        ll sum = 0;  // min n elements sum
        priority_queue<ll>pq1; //maxHeap
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            pq1.push(nums[i]);

            // pop out max elemets
            if(pq1.size() > n){
                sum -= pq1.top();
                pq1.pop(); 
            }
            if(pq1.size() == n){
                prefix[i] = sum;
            }
        }

        sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>>pq2; //maxHeap
        for(int i=nums.size()-1; i>=0; i--){
            sum += nums[i];
            pq2.push(nums[i]);

            // pop out max elemets
            if(pq2.size() > n){
                sum -= pq2.top();
                pq2.pop(); 
            }
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;
        for(int i = n-1; i<2*n; i++){
            ans = min(ans, prefix[i]-suffix[i+1]);
        }
        return ans;

    }
};