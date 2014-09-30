#include <iostream>

using namespace std;


//traverse one time and keep track of zero position
void zero_mark (int** matrix, int row, int col) {
    
    bool* row_status = new bool[row];
    bool* col_status = new bool[col];
    
    for (int i = 0; i < row; i++) {
        row_status[i] = false;
    }
    for (int i = 0; i < row; i++) {
        col_status[i] = false;
    }


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0){
                row_status[i] = true;
                col_status[j] = true;    
            }
        }
    }

    for (int i = 0; i < row; i++) {
        if (row_status[i]) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < col; j++) {
        if (col_status[j]) {
            for (int i = 0; i < row; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    
    int** matrix = new int* [4];
    for (int i = 0; i < 4; i++) {
        matrix[i] = new int [5];
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 1;
        }
    }   
    
    matrix[1][1] = 0;
    matrix[0][4] = 0;
    zero_mark (matrix, 4, 5);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
