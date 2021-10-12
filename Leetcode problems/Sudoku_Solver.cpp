class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char c){
        for(int x=0;x<9;x++){
            if(board[x][j]==c){
                return false;
            }
            if(board[i][x]==c){
                return false;
            }
        }
        int row=i-(i%3);
        int col=j-(j%3);
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[row+x][col+y]==c){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>>& board, int i, int j){
        if(i==9){
            return true;
        }
        if(j==9){
            return sudoku(board, i+1, 0);
        }
        if(board[i][j]!='.'){
            return sudoku(board, i, j+1);
        }
        for(char c='1';c<='9';c++){
            if(check(board,i,j,c)){
                board[i][j]=c;
                if(sudoku(board, i, j+1)){
                    return true;
                }
                board[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board, 0, 0);
    }
};
