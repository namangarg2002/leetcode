class Solution {
    class Car{
        public:
        int pos, speed;
        Car(int _p, int _s): pos(_p), speed(_s) {}
    };
    static bool myComp(Car&a, Car&b){
        return a.pos < b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i=0; i<position.size(); i++){
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), myComp);

        stack<float>st;

        for(auto car: cars){
            float time = (target - car.pos) / ((float)car.speed);
            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        // int count = 0;
        // while(!st.empty()){
        //     // cout<< st.top() << " "; // only for checking the element 
        //     count++;
        //     st.pop();
        // }
        return st.size();
    }
};