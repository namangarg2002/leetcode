class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickM = 0;
        int pickP = 0;
        int pickG = 0;

        int travelM = 0;
        int travelP = 0;
        int travelG = 0;

        int lastM = 0;
        int lastP = 0;
        int lastG = 0;

        // calculate pick time and travel time

        for(int i=0; i<garbage.size(); i++){
            string curr = garbage[i];
            for(int j=0; j<curr.length(); j++){
                char ch = curr[j];
                if(ch=='M'){
                    pickM++;
                    lastM = i;
                }else if(ch=='P'){
                    pickP++;
                    lastP =i ;
                }else if(ch=='G'){
                    pickG++;
                    lastG = i;
                }
            }
        }
        // calculate travell time
        for(int i=0; i<lastM; i++){
            travelM += travel[i];
        }
        for(int i=0; i<lastP; i++){
            travelP += travel[i];
        }
        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }
        

        int ans = (pickM + travelM) + (pickP + travelP) + (pickG + travelG);
        return ans;
    }
};