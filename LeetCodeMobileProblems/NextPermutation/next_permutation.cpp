#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void next_permutation(vector<int> &arr) {
    
    int carry_index;
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (arr[i] < arr[i+1]) {
            carry_index = i;
            break;
        }
    }
    if (carry_index < 0) {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        if (arr[i] > arr[carry_index]) {
            swap(arr[i], arr[carry_index]);
            reverse(arr.begin() + carry_index + 1, arr.end());
            return;
        }
    }
}

int main() {
    vector<int> arr {6, 7, 8, 2, 5};
    next_permutation(arr);
    cout << "result: " << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
