class Solution {
public:
    bool isSafe(int row, int col, char value, vector<vector<char>>& board){
        // same row me vo number na ho
        // same col m vo no. na ho
        // same 3*3 matrix m vo no. na ho

        int n = board.size();
        // same row;
        for(int i=0; i<n; i++){
            if(board[row][i] == value){
                return false;
            }
        }
        // same col
        for(int i=0; i<n; i++){
            if(board[i][col] == value){
                return false;
            }
        }
        // same 3*3 matrix
        for(int i=0; i<n; i++){
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == value){
                return false;
            }
        }
        return true;

    }
    bool solveHelper(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                // empty cell check karo
                if(board[i][j] == '.'){
                    // try 1-9 insert
                    for(char ch = '1'; ch <='9'; ch++){
                        if(isSafe(i, j, ch, board)){
                            // place kardo
                            board[i][j] = ch;
                            // rest recurssion will handle it
                            bool recurssionAns = solveHelper(board);
                            if(recurssionAns == true){
                                return true;
                            }else{
                                // recurssion answer nhi la paya
                                //  iska matlba jo ch apne insert kiya ,  wo galat tha -> backtrack kardo
                                board[i][j] = '.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solveHelper(board);
    }
};