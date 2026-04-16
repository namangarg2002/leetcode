class Solution {
public:
    int daysRequiredToFillCqapacity(vector<int> &weights, int capacity){
        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] <= capacity){
                load += weights[i];
            }else{
                days++;
                load = weights[i];
            }
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;

            int noOfDaysRequired = daysRequiredToFillCqapacity(weights, mid);

            if(noOfDaysRequired <= days){
                ans =  mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};