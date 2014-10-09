#include <iostream>
#include <vector>

using namespace std;

int find_missing (vector<int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];
    return n * (n + 1) / 2 - sum;
}

int main() {
    vector<int> arr {1, 4, 3, 6, 2, 7, 8, 9};
    cout << "result: " << find_missing(arr, 9) << endl; 
}
