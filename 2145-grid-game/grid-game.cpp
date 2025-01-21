class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        // Calculate prefix sums for both rows
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);

        // Prefix sums for the top row
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
        }

        // Prefix sums for the bottom row
        for (int i = 0; i < n; ++i) {
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }

        // Calculate the minimum possible score for the second robot
        long long minSecondRobotScore = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            // Top path sum after i (exclusive)
            long long topRemaining = prefixTop[n] - prefixTop[i + 1];
            // Bottom path sum before i (inclusive)
            long long bottomRemaining = prefixBottom[i];

            // Maximum of the two paths for the second robot
            long long secondRobotScore = max(topRemaining, bottomRemaining);

            // Minimize the second robot's score
            minSecondRobotScore = min(minSecondRobotScore, secondRobotScore);
        }

        return minSecondRobotScore;
    }
};