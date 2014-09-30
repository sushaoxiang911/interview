#include <iostream>
#include <vector>

using namespace std;


void permutations_help(vector<vector<int> > &result, vector<int> arr, 
                        vector<int> current, int index) {
    if (current.size() == arr.size()) {
        result.push_back(current);
        return;
    }

    int new_size = current.size() + 1;
    for (int i = 0; i < new_size; ++i) {
        vector<int> new_current;
        for (int j = 0; j < i; ++j)
            new_current.push_back(current[j]);
        new_current.push_back(arr[index]);
        for (int j = i; j < current.size(); ++j)
            new_current.push_back(current[j]);
        permutations_help(result, arr, new_current, index + 1);
    }

}


vector<vector<int> > permutations(vector<int> arr) {
    vector<vector<int> > result;
    vector<int> current;
    permutations_help(result, arr, current, 0);
    return result;
}

// another way is first given the original array
// we from the first index and swap it with every later ones and we have the results
// and use these result and generate other results for later ones

void swap (int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void permutations_2_help(vector<vector<int> > &result, int size, int index) {
    if (index == size - 1)
        return;
    int current_result_size = result.size();
    for (int i = 0; i < current_result_size; ++i) {
        vector<int> current_arr = result[i];
        for (int j = index + 1; j < size; ++j) {
            swap(current_arr[index], current_arr[j]);
            result.push_back(current_arr);
            swap(current_arr[index], current_arr[j]);
        }
    }
    permutations_2_help(result, size, index + 1);
}

vector<vector<int> > permutations_2(vector<int> arr) {
    vector<vector<int> > result;
    result.push_back(arr);
    permutations_2_help(result, arr.size(), 0);
    return result;
}



int main() {
    vector<int> arr {1, 2, 3};
    vector<vector<int> > result = permutations_2(arr);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
