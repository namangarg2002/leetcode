class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // Step1: first window process 
        for(int i=0; i<k; i++){
            int element  = nums[i];
            // jitne bhi queue ke nader chote no. h unhe remove kr do
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            // now insert karo 
            dq.push_back(i); 
        }

        // Step2: remaining window process
            // removal 1:out of range
            //         2:Choote element ko remove kr do
            // addition
        for(int i=k; i<nums.size(); i++){
            // ans store
            ans.push_back(nums[dq.front()]);

            // removal
            // out of range
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            // chote eleemnt pop krdo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            // addition
            dq.push_back(i);

        }
        // last window ka answer store krlo
        ans.push_back(nums[dq.front()]);

        return ans; 
    }
};