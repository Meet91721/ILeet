class Solution {
public:
    
    bool isValid(vector<vector<char>>&board, char n, int row, int col){
        for(int i = 0; i < 9; i++){
            if(board[row][i]==n)
                return false;
        }
        for(int i = 0; i < 9; i++){
            if(board[i][col]==n)
                return false;
        }
        
        /**/
        int rowindex = 3*(row/3);
        int colindex = 3*(col/3);
        for(int i = rowindex; i<rowindex+3; i++){
            for(int j = colindex; j<colindex+3; j++){
                if(board[i][j]==n)
                    return false;
            }
        }
        
        return true;
    }
    
    
    bool recurse(vector<vector<char>>&board){
        int i = 0; 
        int j = 0;
        bool found = false;
        for(; i < 9; i++){
            for(j=0; j < 9; j++){
                if(board[i][j] == '.')
                {
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        if(i == 9 && j == 9){
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                }
            }
            return true;
        }

        for(int x = 1; x < 10; x++){
            char num = '0'+x;
            if(!isValid(board, num, i, j))
                continue;
            board[i][j]=num;
            if(recurse(board))
                return true;
            board[i][j]='.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        recurse(board);
    }
};