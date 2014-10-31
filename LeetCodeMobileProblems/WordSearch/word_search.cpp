#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dfs

bool word_search_helper(vector<vector<char> > grid, string word, int index, int row, int col,
                        vector<vector<bool> > &path) {
    if (index == word.size())
        return true;
    if (row != 0 && !path[row-1][col]) {
        if (grid[row-1][col] == word[index]) {
            path[row-1][col] = true;
            if (word_search_helper(grid, word, index + 1, row - 1, col, path))
                return true;
            path[row-1][col] = false;
        }
    }
    if (col != 0 && !path[row][col-1]) {
        if (grid[row][col-1] == word[index]) {
            path[row][col-1] = true;
            if (word_search_helper(grid, word, index + 1, row, col - 1, path))
                return true;
            path[row][col-1] = false;
        }
    }
    if (row != grid.size() - 1 && !path[row+1][col]) {
        if (grid[row+1][col] == word[index]) {
            path[row+1][col] = true;
            if (word_search_helper(grid, word, index + 1, row + 1, col, path))
                return true;
            path[row+1][col] = false;
        }
    }
    if (col != grid[0].size() - 1 && !path[row][col+1]) {
        if (grid[row][col+1] == word[index]) {
            path[row][col+1] = true;
            if (word_search_helper(grid, word, index + 1, row, col + 1, path))
                return true;
            path[row][col+1] = false;
        }
    }
    return false;
}
bool word_search_helper_2(vector<vector<char> > grid, string word, int index, int row, int col,
                            vector<vector<bool> > &path) {
    if (index == word.size())
        return true;
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || path[row][col])
        return false;
    if (grid[row][col] == word[index]) {
        path[row][col] = true;
        if (word_search_helper_2(grid, word, index + 1, row + 1, col, path) ||
                word_search_helper_2(grid, word, index + 1, row - 1, col, path) ||
                word_search_helper_2(grid, word, index + 1, row, col + 1, path) ||
                word_search_helper_2(grid, word, index + 1, row, col - 1, path))
            return true;
        else {
            path[row][col] = false;
            return false;
        }

    } else 
        return false;
}

bool word_search_2(vector<vector<char> > grid, string word) {
    if (word == "")
        return true;
    if (grid.size() == 0 || grid[0].size() == 0)
        return false;
    vector<vector<bool> > path(grid.size(), vector<bool> (grid[0].size(), false));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (word_search_helper_2(grid, word, 0, i, j, path))
                return true;
        }
    }
    return false;
}

bool word_search(vector<vector<char> > grid, string word) {
    if (word == "")
        return true;
    if (grid.size() == 0 || grid[0].size() == 0)
        return false;
    
    vector<vector<bool> > path(grid.size(), vector<bool> (grid[0].size(), false));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == word[0]) {
                path[i][j] = true;
                if (word_search_helper(grid, word, 1, i, j, path))
                    return true;
                path[i][j] =  false;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char> > grid {    {'A', 'B', 'C', 'E'},
                                    {'S', 'F', 'C', 'S'},
                                    {'A', 'D', 'E', 'E'}};


    cout << "result: " << word_search_2(grid, "ABCB") << endl;
}





