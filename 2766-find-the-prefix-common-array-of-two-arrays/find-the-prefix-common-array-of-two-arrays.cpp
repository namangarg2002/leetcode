class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n, 0);
        unordered_set<int> seenA, seenB;
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {

            seenA.insert(A[i]);
            seenB.insert(B[i]);

            if (A[i] == B[i]) {
                commonCount++;
            } else {
                if (seenB.count(A[i])) {
                    commonCount++;
                }
                if (seenA.count(B[i])) {
                    commonCount++;
                }
            }

            prefixCommonArray[i] = commonCount;
        }

        return prefixCommonArray;
    }
};