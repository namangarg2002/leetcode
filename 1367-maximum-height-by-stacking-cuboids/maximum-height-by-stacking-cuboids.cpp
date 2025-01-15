class Solution {
public:
    bool check(vector<int> &curr, vector<int>&prev){
        // curr -> bade wale dabbe ko
        // prev -> chotte wale dubbe ko
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }else{
            return false;
        }
    }
    int solveUsingTabulationSpaceOptimization(vector<vector<int>>& cuboids){
        int n = cuboids.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int curr_index=n-1; curr_index>=0; curr_index--){
            for(int prev_index=curr_index-1; prev_index>=-1; prev_index--){
                int include = 0;
                if(prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])){
                    int heightToAdd = cuboids[curr_index][2];
                    include = heightToAdd + next[curr_index+1];
                }
                int exclude = 0 + next[prev_index+1];

                curr[prev_index+1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto&cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        int ans = solveUsingTabulationSpaceOptimization(cuboids);

        return ans;
    }
};