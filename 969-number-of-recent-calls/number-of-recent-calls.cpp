class RecentCounter {
    queue<int>q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // 1.
        q.push(t);

        // 2. pop invalid req. older than t-3000
        while(!q.empty() && q.front() < (t-3000)){
            q.pop();
        }

        // 3. mow q has only number of recent calls return q.size();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */