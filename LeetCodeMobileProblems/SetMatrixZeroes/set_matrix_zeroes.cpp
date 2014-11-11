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

// to set the whole row and col zeros
// we can use the matrix itself to keep track of the rows and cols that we are 
// going to set
//
// Thing to be considered is that we use the first row as the row record vector
// and the first col as the col record vector
// we have to know if we should set first row and first col to zero
//
// So that needs to use to flag to remember before we traverse the matrix


void set_zeroes_2(vector<vector<int> > &matrix) {
    if (matrix.empty())
        return;
    if (matrix[0].empty())
        return;
    int row_size = matrix.size();
    int col_size = matrix[0].size();

    bool rflag = false;
    bool cflag = false;
    for (int i = 0; i < row_size; ++i) {
        if (matrix[i][0] == 0) {
            cflag = true;
            break;
        }
    }

    for (int j = 0; j < col_size; ++j) {
        if (matrix[0][j] == 0) {
            rflag = true;
            break;
        }
    }

    for (int i = 1; i < row_size; ++i) {
        for (int j = 1; j < col_size; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < row_size; ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < col_size; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < col_size; ++j) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < row_size; ++i) {
                matrix[i][j] = 0;
            }
        }
    }

    if (rflag) {
        for (int j = 0; j < col_size; ++j) {
            matrix[0][j] = 0;
        }
    }

    if (cflag) {
        for (int i = 0; i < row_size; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int> > matrix {   {0, 3, 0, 1}, 
                                    {3, 5, 3, 2}, 
                                    {0, 1, 3, 4}};
    set_zeroes_2(matrix);
    cout << "result: " << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
