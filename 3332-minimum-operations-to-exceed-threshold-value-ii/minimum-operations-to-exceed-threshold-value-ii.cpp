class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end());

        long long operations = 0;

        while (minHeap.size() > 1 && minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long newElement = 2 * std::min(x, y) + std::max(x, y);

            minHeap.push(newElement);

            operations++;
        }

        if (minHeap.top() >= k) {
            return operations;
        } else {
            return -1;
        }
    }
};