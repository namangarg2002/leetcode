class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        // all player should go into a Queue
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        while(q.size() > 1){
            // Simulate the game
            for(int i=1; i<k; i++){
                auto player = q.front();
                q.pop();

                // it is not eliminated yet
                q.push(player);
            }
            // kth player must be deleted.
            q.pop();
        }
        return q.front();
    }
};