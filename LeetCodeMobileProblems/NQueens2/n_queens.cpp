#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void n_queens_help(vector<int> arr, int n, int &count) {
    if (arr.size() == n) {
        ++count;
        return;
    }
    for (int i = 0; i < n; ++i) {
        arr.push_back(i);
        // push_back a new queen
        int new_queen = arr.back();
        int new_index = arr.size() - 1;
        bool flag = true;
        for (int j = 0; j < arr.size() - 1; ++j) {
            if (abs(new_index - j) == abs(new_queen - arr[j]) || new_queen == arr[j]) {
                flag = false;
                break;
            }
        }        
        if (flag) {
            n_queens_help(arr, n, count);
        }
        arr.pop_back();
    }
}


int n_queens(int n) {
    int count = 0;
    vector<int> arr;
    arr.clear();
    n_queens_help(arr, n, count);
    return count;
}

int main() {
    cout << "result: " << n_queens(8) << endl;
}
