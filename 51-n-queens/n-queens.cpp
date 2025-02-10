class Solution {
public:
    unordered_map<int, bool>rowCheck;
    unordered_map<int, bool>topDiagonal;
    unordered_map<int, bool>bottomDiagonal;
    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans){
        vector<string>tempSol;
        for(auto vec:board){
            string temp = "";
            for(auto ch:vec){
                temp.push_back(ch);
            }
            tempSol.push_back(temp);
        }
        ans.push_back(tempSol);
    }
    bool isSafe(int row, int col, vector<vector<char>> board){
        if(rowCheck[row] == true){
            return false;
        }
        if(topDiagonal[col-row] == true){
            return false;
        }
        if(bottomDiagonal[row+col] == true){
            return false;
        }

        return true;
    }
    void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col){
        // base case
        if(col >= n){
            // sare column process ho gaye hai we have a solution to store
            storeSolution(board, ans);
            return;
        }
        // main login
        // is column ke har row pr queen place kr ke dekkho
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board)){
                // queen place kardo
                board[row][col] = 'Q';
                // mark all three direction that queue is flaced here
                rowCheck[row] = true;
                topDiagonal[col-row] = true;
                bottomDiagonal[row+col]  = true;

                // recurssion
                solve(board, ans, n, col+1);
                // backTracking
                board[row][col] = '.';
                rowCheck[row] = false;
                topDiagonal[col-row] = false;
                bottomDiagonal[row+col]  = false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(board, ans, n, col);
        return ans;
    }
};