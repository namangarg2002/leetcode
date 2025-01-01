class Solution {
public: 
    int maxScore(string s) {
        // // M1: Brute Force (1st jan 2025)
        // int n = s.length();
        // int result = INT_MIN;

        // for(int i=0; i<= n-2; i++){
        //     // 0 to i - zero count
        //     int zero_count = 0;
        //     for(int j=0; j<=i; j++){
        //         if(s[j] == '0'){
        //             zero_count++;
        //         }
        //     }
        //     // i+1 to n-1 - one count
        //     int one_count = 0;
        //     for(int j=i+1; j<n; j++){
        //         if(s[j] == '1'){
        //             one_count++;
        //         }
        //     }
        //     result = max(result, zero_count+one_count);
        // }
        // return result;

        // // M2: 2 pass Approach
        // int n = s.length();
        // int result = INT_MIN;

        // int total_ones = count(begin(s), end(s), '1'); //1st pass

        // int zeros = 0;
        // int ones = 0;
        // // right_ones = total_ones - ones

        // for(int i=0; i<=n-2; i++){
        //     if(s[i] == '0'){
        //         zeros++;
        //     }
        //     else{
        //         ones++;
        //     }
        //     int right_ones = total_ones - ones;
        //     result = max(result, zeros+right_ones);
        // }
        // return result;

        // M3: One pass Algo
        int n = s.length();

        int score = INT_MIN;
        int zeros = 0;
        int ones = 0;
        for(int i=0; i<=n-2; i++){
            if(s[i]=='1') ones++;
            else zeros++;
            score = max(score, zeros-ones);
        }
        if(s[n-1]=='1'){
            ones++;
        }

        return score + ones;


    }
};