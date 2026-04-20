class Solution {
public:
    int countpainter(vector<int> &boards, int paints){
        int painter = 1;
        int paintBoards = 0;
        for(int i=0; i<boards.size(); i++){
            if(paintBoards + boards[i] <= paints){
                paintBoards += boards[i];
            }else{
                painter++;
                paintBoards = boards[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
    
        while(s<=e){
            int mid = s + (e-s)/2;
            int cntPainter = countpainter(nums, mid);
            if(cntPainter > k){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
    }
};