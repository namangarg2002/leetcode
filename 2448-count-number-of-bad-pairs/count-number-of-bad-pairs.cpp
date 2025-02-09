class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // long long count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(j-i != nums[j]-nums[i]){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        unordered_map<int, long long> freq;
        long long totalPairs = 0, goodPairs = 0;

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] - i;
            
            if (freq.find(key) != freq.end()) {
                goodPairs += freq[key];
            }


            freq[key]++;

            totalPairs += i;
        }

        return totalPairs - goodPairs;
    }
};