class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; 
        int openUnlocked = 0, closeUnlocked = 0; 
        int balance = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                balance += (s[i] == '(' ? 1 : -1);
            } else {
                openUnlocked++;
            }
            if (balance + openUnlocked < 0) return false;
        }

        balance = 0;
        closeUnlocked = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                balance += (s[i] == ')' ? 1 : -1);
            } else {
                closeUnlocked++;
            }
            if (balance + closeUnlocked < 0) return false; 
        }

        return true;
    }
};