#include <iostream>
#include <vector>

using namespace std;

// search linear from top-right to bottom left
bool search_matrix(vector<vector<int> > matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] ==  target) 
            return true;
        if (matrix[row][col] > target)
            --col;
        else
            ++row;
    }
    return false;
}

// two binary search
bool search_matrix_2(vector<vector<int> > matrix, int target) {
    int begin = 0; 
    int end = matrix.size() - 1;

    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (matrix[mid][0] == target) 
            return true;
        if (matrix[mid][0] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    int row = begin - 1;
    if (row < 0) 
        return false;
    begin = 0;
    end = matrix[0].size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (matrix[row][mid] == target)
            return true;
        if (matrix[row][mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int> > matrix {   {1, 3, 5, 7}, 
                                    {10, 12, 16, 20}, 
                                    {23, 30, 34, 50}};
    cout << "result: " << search_matrix_2(matrix, 14) << endl;

}





