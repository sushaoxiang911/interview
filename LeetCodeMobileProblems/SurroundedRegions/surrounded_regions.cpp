#include <vector>
#include <iostream>

using namespace std;

void traversal (int n, int m, vector<vector<char> > &board, 
                int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
        board[x][y] = 'Z';
        traversal(n, m, board, x - 1, y);
        traversal(n, m, board, x + 1, y);
        traversal(n, m, board, x, y + 1);
        traversal(n, m, board, x, y - 1);
    }
}

void surrounded_regions(vector<vector<char> > &board) {
    if (board.empty() || board[0].empty())
        return;
    int n = board.size();
    int m = board[0].size();
    
    for (int i = 0; i < n; ++i) {
        if (board[i][0] == 'O')
            traversal(n, m, board, i, 0);
        if (board[i][m-1] == 'O')
            traversal(n, m, board, i, m-1);  
    }
    for (int i = 0; i < m; ++i) {
        if (board[0][i] == 'O')
            traversal(n, m, board, 0, i);
        if (board[n-1][i] == 'O')
            traversal(n, m, board, n - 1, i);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = (board[i][j] == 'Z' ? 'O' : 'X');
        }
    }
}

int main() {
    vector<vector<char> > board {   {'X', 'X', 'X', 'X'},
                                    {'X', 'O', 'O', 'X'},
                                    {'X', 'O', 'O', 'X'},
                                    {'X', 'O', 'X', 'X'}};
    surrounded_regions(board);
    cout << "result: " << endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
} 
