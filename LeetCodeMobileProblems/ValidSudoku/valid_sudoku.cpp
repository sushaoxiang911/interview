#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<vector<char> > board) {
    vector<vector<vector<bool> > >
        check(3, vector<vector<bool> > (9, vector<bool> (9, true)));
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                // check row
                if (check[0][i][board[i][j]-'1'])
                    check[0][i][board[i][j]-'1'] = false;
                else
                    return false;
                if (check[1][j][board[i][j]-'1'])
                    check[1][j][board[i][j]-'1']
                else
                    return false;
                if (check[2][i/3*3+j/3][board[i][j]-'1'])
                    check[2][i/3*3+j/3][board[i][j]-'1'] = false
                else
                    return true;
            }
        }
    }
    return true;
}
