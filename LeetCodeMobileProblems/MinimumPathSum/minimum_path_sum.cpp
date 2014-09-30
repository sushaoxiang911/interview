#include <iostream>
#include <vector>

using namespace std;

int get_minimum(vector<vector<int> > grid) {
    if (grid.empty())
        return 0;
    vector<vector<int> > path(grid.size(), vector<int> (grid[0].size(), 0));
    
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (i == 0 && j == 0)
                break;
            else if (i == 0 && j != 0) {
                path[i][j] = path[i][j-1] + grid[i][j-1];
            } else if (i != 0 && j == 0) {
                path[i][j] = path[i-1][j] + grid[i-1][j];
            } else {
                path[i][j] = path[i][j-1] + grid[i][j-1];
                if (path[i][j] > path[i-1][j] + grid[i-1][j])
                    path[i][j] = path[i-1][j] + grid[i-1][j];
            }
        }
    }
    return path[grid.size()-1][grid[0].size()-1];
}

int main() {
    vector<vector<int> > grid (3, vector<int> (3, 0));
    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[0][2] = 3;
    grid[1][0] = 1;
    grid[1][1] = 3;
    grid[1][2] = 2;
    grid[2][0] = 9;
    grid[2][1] = 7;
    grid[2][2] = 5;
    
    cout << "result: " << get_minimum(grid) << endl;
}
