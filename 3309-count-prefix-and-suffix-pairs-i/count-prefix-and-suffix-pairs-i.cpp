class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        // Check if str1 is longer than str2
        if (len1 > len2) return false;

        // Check if str1 is a prefix of str2
        if (str2.substr(0, len1) != str1) return false;

        // Check if str1 is a suffix of str2
        if (str2.substr(len2 - len1, len1) != str1) return false;

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        // Iterate over all pairs (i, j) where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};