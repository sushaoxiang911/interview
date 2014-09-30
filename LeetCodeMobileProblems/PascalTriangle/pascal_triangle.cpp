#include <iostream>
#include <vector>

using namespace std;

void pascal_triangle_help(vector<vector<int> > &result, int num, 
                            vector<int> former, int current) {
    if (current == num + 1)
        return;
    
    vector<int> new_row;
    if (current == 1) {
        new_row.push_back(1);
        result.push_back(new_row);
    } else {
        for (int i = 0; i < current; ++i) {
            if (i == 0)
                new_row.push_back(1);
            else if (i == current - 1)
                new_row.push_back(1);
            else {
                new_row.push_back(former[i-1] + former[i]);
            }
        }
        result.push_back(new_row);
    }
    pascal_triangle_help(result, num, new_row, current + 1); 
}

vector<vector<int> > pascal_triangle(int num) {
    vector<vector<int> > result;
    vector<int> former;
    pascal_triangle_help(result, num, former, 1);
    return result;
}

int main() {
    vector<vector<int> > result = pascal_triangle(5);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
