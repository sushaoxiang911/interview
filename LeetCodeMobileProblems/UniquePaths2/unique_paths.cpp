#include <iostream>
#include <vector>

using namespace std;


int unique_paths(vector<vector<int> > grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    
    vector<vector<int> > path(grid.size(), vector<int> (grid[0].size(), 0));
    
    int n = grid.size();
    int m = grid[0].size();
    path[0][0] = 1;    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1)
                path[i][j] = 0; 
            else {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0) {
                    if (grid[i][j-1] == 1)
                        path[i][j] = 0;
                    else
                        path[i][j] = path[i][j-1];
                } else if (j == 0) {
                    if (grid[i-1][j] == 1)
                        path[i][j] = 0;
                    else
                        path[i][j] = path[i-1][j];
                } else {
                    int temp = 0;
                    if (grid[i][j-1] == 0)
                        temp += path[i][j-1];
                    if (grid[i-1][j] == 0)
                        temp += path[i-1][j];
                    path[i][j] = temp;
                }
            }
        }
    }
    return path[n-1][m-1];
}

// we use 0 to set non path
// so we can still use the result from the previous solution
int unique_paths_2 (vector<vector<int> > grid) {
    if (grid.empty() || grid[0].empty())
        return 0;

    vector<vector<int> > path(grid.size(), vector<int> (grid[0].size(), 0));
    int n = grid.size();
    int m = grid[0].size();
    path[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == 1) {
            path[i][0] = 0;
        } else {
            path[i][0] = path[i-1][0];
        }
    }
    for (int j = 1; j < m; ++j) {
        if (grid[0][j] == 1)
            path[0][j] = 0;
        else
            path[0][j] = path[0][j-1];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 1)
                path[i][j] = 0;
            else
                path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }
    return path[n-1][m-1];
}

int main() {
    vector<vector<int> > grid { {0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}};
    cout << "result: " << unique_paths_2(grid) << endl;

}
