class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int,int>>pq; // {fuel, position}

        while(true){
            while(i<stations.size()){
                // push stations within the reach with my current fule levels from my current positions
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }else{
                    break;
                }
                i++;
            }

            // travel with full fuel level
            dist += fuel;
            fuel = 0;

            // reached
            if(dist >= target){
                break;
            }

            // no fuel station station within reach
            if(pq.empty()){
                stops = -1;
                break;
            }

            // refuel ans readjust distance & fuel based on the distance travelled and fuel used till that stations
            auto&top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop();
            stops++;
            
        }
        return stops;

    }
};