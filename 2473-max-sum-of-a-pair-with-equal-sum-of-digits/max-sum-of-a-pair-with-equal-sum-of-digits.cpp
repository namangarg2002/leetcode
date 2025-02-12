class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; 
        int maxSum = -1;

        for (int num : nums) {
            int sum = digitSum(num); 

            
            if (digitSumMap.find(sum) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sum] + num);
            }

            digitSumMap[sum] = max(digitSumMap[sum], num);
        }

        return maxSum;
    }
};