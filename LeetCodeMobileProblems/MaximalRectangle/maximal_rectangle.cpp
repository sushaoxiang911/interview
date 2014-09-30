#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// consider the maximal rectangle in histogram
// consider a 1 and regard it as the down-left corner
// and from it expand right
// we can treat this 1's x axis as the x axis of a histogram and consecutive down 1's as the bar
// and calculate the biggest rectangle

// first we transfer the grid to row's of histogram
// every number of the new grid is the height of the bar starting from this one

int find_bar_chart_largest (vector<int> bar) {
    if (bar.empty())
        return 0;
    stack<int> index;
    stack<int> height;

    int max_size = 0;


    for (int i = 0; i < bar.size(); ++i) {
        int current_height = bar[i];
        if (index.empty() || height.top() < current_height) {
            index.push(i);
            height.push(current_height);
        } else if (height.top() > current_height){
            int new_index = i;

            int temp_height = height.top();
            while (temp_height > current_height) {
                height.pop();

                int rec_start_pos = index.top();
                index.pop();
                int temp_max = temp_height * (i - rec_start_pos);

                // cannot simply -- since the position is not directing mapping
                new_index = rec_start_pos;

                if (temp_max > max_size)
                    max_size = temp_max;

                if (height.empty())
                    break;
                temp_height = height.top();
            }
            index.push(new_index);
            height.push(current_height);
        }
    }
    while (index.size() > 0) {
        int new_index = index.top();
        int new_height = height.top();

        index.pop();
        height.pop();

        int temp_size = new_height * (bar.size() - new_index);
        if (temp_size > max_size)
            max_size = temp_size;
    }
    return max_size;
}
                                      
int get_maximal(vector<vector<int> >grid) {
    if (grid.empty())
        return 0;
    vector<vector<int> >charts(grid.size(), vector<int> (grid[0].size(), 0));
    
    charts[0] = grid[0];
    for (int i = 1; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) {
                charts[i][j] = charts[i-1][j] + 1;
            }
        }
    }
    int max_size = 0;
    for (int i = 0; i < charts.size(); ++i) {
        int temp_size = find_bar_chart_largest(charts[i]);
        if (temp_size > max_size)
            max_size = temp_size;
    }
    return max_size;
}

int main() {
    vector<vector<int> > grid(4, vector<int> (4, 0));
    grid[0][2] = 1;
    grid[1][3] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    
    cout << "result: " << get_maximal(grid) << endl;
}





