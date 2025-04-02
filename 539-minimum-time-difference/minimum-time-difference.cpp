class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>Time;
        for(auto& s:timePoints){
            int colonPos = s.find(':');
            int hours = stoi(s.substr(0, colonPos));
            int minutes = stoi(s.substr(colonPos+1));

            int totalMinutes = hours*60+minutes;
            int minutesToPush = (1440-totalMinutes)%1440;
            Time.push_back(minutesToPush);
        }
        sort(Time.begin(), Time.end());

        int minTime = INT_MAX;
        for(int i=1; i<Time.size(); i++){
            minTime = min(minTime, Time[i]-Time[i-1]);
        }
        int circularDiff = (Time[0] + 1440) - Time.back();
        minTime = min(minTime, circularDiff);

        return minTime;
    }
};