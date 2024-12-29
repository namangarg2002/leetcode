class MedianFinder {
private:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        }
        else if (maxHeap.size() > minHeap.size()) {
            if (num >= maxHeap.top()) {
                minHeap.push(num);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else {
            if (num <= minHeap.top()) {
                maxHeap.push(num);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */