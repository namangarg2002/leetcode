class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>answer(cars.size(), -1); // collision time of ith cars with the next car.
        stack<int>st;
        for(int i=cars.size()-1; i>=0; i--){
            // check if car of current is faster?
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            while(!st.empty()){
                double colTime = ((double)(cars[st.top()][0] - cars[i][0])) / (abs(cars[st.top()][1] - cars[i][1]));
                if(answer[st.top()] == -1 || colTime <= answer[st.top()]){
                    answer[i] = colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return answer;

    }
};