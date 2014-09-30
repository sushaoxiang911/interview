#include <iostream>
#include <vector>

using namespace std;

// first swap by columns
// then swap with diagonal line

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    // swap by columns
    int mid = n / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mid; ++j) {
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
    // swap with digonal line
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
}

int main() {
    vector<vector<int> > matrix = { {1, 2, 3, 4}, 
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}};
    rotate(matrix);
    cout << "result: " << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
