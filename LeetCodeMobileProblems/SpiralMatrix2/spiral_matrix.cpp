#include <iostream>
#include <vector>

using namespace std;

void spiral_help(int rs, int re, int cs, int ce, int start, vector<vector<int> > &matrix) {
    if (rs == re) {
        matrix[rs][cs] = start;
        return;
    }
    for (int i = cs; i < ce; ++i) {
        matrix[rs][i] = start;
        start++;
    }
    for (int i = rs; i < re; ++i) {
        matrix[i][ce] = start;
        start++;    
    }
    for (int i = ce; i > cs; --i) {
        matrix[re][i] = start;
        start++;
    }
    for (int i = re; i > rs; --i) {
        matrix[i][cs] = start;
        start++;
    }
    spiral_help(rs + 1, re - 1, cs + 1, cs - 1, start, matrix);
}



vector<vector<int> > spiral(int n) {
    vector<vector<int> > matrix(n, vector<int> (n, 0));
    spiral_help(0, n - 1, 0, n - 1, 1, matrix);
    return matrix;
}

int main() {
    vector<vector<int> > matrix = spiral(3);
    cout << "result: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
