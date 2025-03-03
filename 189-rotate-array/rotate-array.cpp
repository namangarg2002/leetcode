class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>rotated(n);
        for(int i=0; i<n; i++){
            int newIndex = (i + k) % n;
            rotated[newIndex] = nums[i];
        }
        for(int i=0; i<n; i++){
            nums[i] = rotated[i];
        }
    }
};