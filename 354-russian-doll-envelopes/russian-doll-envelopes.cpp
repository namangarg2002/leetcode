class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        }
    };

    int solveUsingBS(vector<vector<int>>& envelopes) {
        vector<int> ans;

        for (const auto& envelope : envelopes) {
            int weight = envelope[1];

            auto index = lower_bound(ans.begin(), ans.end(), weight);

            if (index == ans.end()) {
                ans.push_back(weight);
            } else {
                *index = weight;
            }
        }

        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), Compare());

        // Solve using the binary search approach
        return solveUsingBS(envelopes);
    }
};