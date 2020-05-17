//a solution of sudoku
bool has_conflicts(std::vector<std::vector<char>>& board, int row, int col, char letter){
        //for row
        //for column
        for(int i = 0; i < 9; i ++){
            if(i != col && board[row][i] == letter){
                return true;
            }
            if(i != row && board[i][col] == letter){
                return true;
            }
        }
        int start_col = (col / 3) * 3;
        int start_row = (row /3) * 3;
        for(int r = 0; r < 3; r++ ){
            int board_r = start_row + r;
            for(int c = 0; c < 3; c++){
                int board_c = start_col + c;
                if(board_r != row && board_c != col && board[board_r][board_c] == letter){
                    return true;
                }
            }
        }  
        return false;

    }
    
    bool sudoku_bk(std::vector<std::vector<char>>& board, int row, int col){
        if(row == 9 && col == 0){
            return true;
        }
        while(row < 9 && col < 9){
            if(board[row][col] == '.'){
               break; 
            }
            if(col+1 < 9){
                col++;
            }else if(row +1 < 9){
                col = 0;
                row+=1;
            }else{
                return true;
            }
        }
        for(int i = 0; i < 9; i++){
            char c = '1' + i;
            if(!has_conflicts(board, row, col, c)){
                board[row][col] = c;
                if(col +1 < 9){
                    if(sudoku_bk(board, row, col+1)){
                        return true;
                    }
                }else if(row+1 < 9){
                    if(sudoku_bk(board, row+1, 0)){
                        return true;
                    }
                }else{
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
