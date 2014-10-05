#include <iostream>
#include <vector>

using namespace std;

// use O(m+n) space

void set_zeroes(vector<vector<int> > &matrix) {
    if (matrix.empty())
        return;
    if (matrix[0].empty())
        return;
    int row_size = matrix.size();
    int col_size = matrix[0].size();

    vector<bool> row_zero(row_size, false);
    vector<bool> col_zero(col_size, false);
    

    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < col_size; ++j) {
            if (matrix[i][j] == 0) {
                row_zero[i] = true;
                col_zero[j] = true;
            }
        }   
    }

    for (int i = 0; i < row_size; ++i) {
        if (row_zero[i]) {
            for (int j = 0; j < col_size; ++j)
                matrix[i][j] = 0;
        }
    }
    
    for (int j = 0; j < col_size; ++j) {
        if (col_zero[j]) {
            for (int i = 0; i < row_size; ++i)
                matrix[i][j] = 0;
        }
    }
}
/*
// constant space is to every level, every level check
void set_zeroes_2(vector<vector<int> > &matrix) {
    if (matrix.empty())
        return;
    if (matrix[0].empty())
        return;
    int row_size = matrix.size();
    int col_size = matrix[0].size();
    
    int row = 1;
    int col = 1;


    while (row < row_size && col < col_size) {
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;


        // check previous level
        for (int i = row - 1; i < row_size; ++i) {
            if (matrix[i][col-1] == 0) 
                matrix[i][col] = 0;
        }
        for (int j = col - 1; j < col_size; ++j) {
            if (matrix[row-1][j] == 0)
                matrix[row][j] = 0;
        }
        
        for (int i = row; i < row_size; ++i) {
            if (matrix[i][col] == 0) {
                for (int j = 0; j < col; ++j)
                    matrix[i][j] = 0;
            }
        }
        for (int j = col; j < col_size; ++j) {
            if (matrix[row][j] == 0) {
                for (int i = 0; i < row; ++i)
                    matrix[i][j] = 0;
            }
        }
        row++;
        col++;
    }
     
}

*/
int main() {
    vector<vector<int> > matrix {   {0, 3, 0, 1}, 
                                    {3, 5, 3, 2}, 
                                    {0, 1, 3, 4}};
    set_zeroes(matrix);
    cout << "result: " << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
