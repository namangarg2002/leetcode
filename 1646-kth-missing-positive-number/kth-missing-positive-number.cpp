class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int missing = arr[mid] - mid - 1;
            if(missing < k){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return e + 1 + k;
    }
};