#include <iostream>
#include <vector>


// 利用NP的思想完成，为了加快运算速度，我利用了三个数组来保存横列、纵列、方形中的数字重复。


num[3][9][9];
void solveSudoku(vector<vector<char> > &board) {  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 9; j++) {  
            for (int k = 0; k < 9; k++) {  
                num[i][j][k] = true;  
            }  
        }  
    }
    // if there is a number on the board
    // keep track of it in the num[3][9][9]
    // first if which row it belongs
    // then the ith row and the number is taken
    
    // similarly,
    // the jth col and the number is taken
    // calculate which square it belongs to
    for (int i = 0; i < 9; i++) {  
        for(int j = 0; j < 9; j++) {  
            if (isInteger(board[i][j])) {  
                num[0][i][board[i][j]-'1'] = false;  
                num[1][j][board[i][j]-'1'] = false;  
                num[2][i/3*3+j/3][board[i][j]-'1'] = false;  
            }  
        }  
    }  
    fillValidSudoku(0, 0, board);  
}  
      

// it is an NP problem, using the num to prune the number
// when doing a tree expansion, using recursion is a better way
bool fillValidSudoku(int i,int j,vector<vector<char> > &board) {
    // we arrive at a new row  
    if(j == 9) {  
        i++;  
        j = 0;  
    }  
    // we finished fill the last number
    if(i == 9 && j == 0){  
        return true;  
    // if already filled, go next
    } else if(isInteger(board[i][j])) {
        return fillValidSudoku(i, j + 1, board);
    // we arrive at a '.' and trying to fill it
    } else {  

        for(int k = 1; k <= 9; k++) {
            // if we can fill this number
            if(num[0][i][k-1]&&
                    num[1][j][k-1]&&
                    num[2][i/3*3+j/3][k-1]) {  
                

                board[i][j]='0' + k;  
                num[0][i][k-1] = false;  
                num[1][j][k-1] = false;  
                num[2][i/3*3+j/3][k-1] = false;  

                // after we fill this number, if we can get the result
                if(fillValidSudoku(i, j + 1, board)) {  
                    return true;  
                // this result is not true
                // we return it to the original state
                } else {  
                    num[0][i][k-1] = true;  
                    num[1][j][k-1] = true;  
                    num[2][i/3*3+j/3][k-1] = true;  
                    board[i][j] = '.';  
                }  
            }  
        }  
        // we expand all of them and oops, false
        return false;  
    }  
          
}  
  
bool isInteger(char c) {  
    if(c - '0' >= 1 && c - '0' <= 9) {  
        return true;  
    }  
    return false;  
}  
