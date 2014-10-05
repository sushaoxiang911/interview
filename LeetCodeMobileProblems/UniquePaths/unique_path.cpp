#include <iostream>
#include <vector>

using namespace std;

int unique_path(int n, int m) {
    if (m == 0 || n == 0)
        return 0;
    vector<vector<int> > path(n, vector<int> (m, 0));
    // border is 1
    // so we don't need to consider border in next loop
    for (int i = 0; i < n; ++i)
        path[i][0] = 1;
    for (int i = 0; i < m; ++i)
        path[0][i] = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; j++) {
            path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }
    return path[n-1][m-1];
}

int main() {
    cout << "result: " << unique_path(3, 7) << endl;
}
