class Solution {
public:
    bool canPartition(string s, int target, int index, int currentSum) {
        if (index == s.size()) {
            return currentSum == target;
        }

        int num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0'); // Convert substring to integer
            if (num + currentSum > target) break; // Prune unnecessary computations
            if (canPartition(s, target, i + 1, currentSum + num)) {
                return true;
            }
        }
        return false;
    }
    bool isValid(int n) {
        int squared = n * n;
        string s = to_string(squared);
        return canPartition(s, n, 0, 0);
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                sum += i * i;
            }
        }
        return sum;
    }
};