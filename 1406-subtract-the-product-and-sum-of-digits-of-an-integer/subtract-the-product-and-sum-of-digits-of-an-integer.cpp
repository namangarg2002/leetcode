class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;

        while(n > 0){
            digits.push_back(n % 10);
            n/=10;
        }
        int sum = 0;
        int product = 1;

        for(int i=0; i<digits.size(); i++){
            sum+=digits[i];
            product*=digits[i];
        }
        int ans = product-sum;
        return ans;
    }
};