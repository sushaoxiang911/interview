#include <iostream>
#include <vector>

using namespace std;


void swap (int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// to eliminate the duplicate
// we have to guarantee that current_arr[index] would swap with current_arr[j]
// that from index to j-1, there is no number equals to current_arr[j]


void permutations_help(vector<vector<int> > &result, int size, int index) {
    if (index == size - 1)
        return;
    int current_result_size = result.size();
    for (int i = 0; i < current_result_size; ++i) {
        vector<int> current_arr = result[i];
        for (int j = index + 1; j < size; ++j) {
            bool exist = false;
            for (int k = index; k < j; k++) {
                if (current_arr[k] == current_arr[j]) {
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                swap(current_arr[index], current_arr[j]);
                result.push_back(current_arr);
                swap(current_arr[index], current_arr[j]);
            }
        }
    }
    permutations_help(result, size, index + 1);
}

vector<vector<int> > permutations(vector<int> arr) {
    vector<vector<int> > result;
    result.push_back(arr);
    permutations_help(result, arr.size(), 0);
    return result;
}



int main() {
    vector<int> arr {1, 1, 2, 2};
    vector<vector<int> > result = permutations(arr);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}

