#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int find_maximum_product(vector<int> &arr) {
    int result = arr[0];
    int max_result = arr[0];
    int min_result = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        cout << "max result: " << max_result << endl;
        cout << "min result: " << min_result << endl;
        if (arr[i-1] == 0) {
            max_result = arr[i];
            min_result = arr[i];
            result = result > max_result ? result : max_result;
            continue;
        }
        if (arr[i] > 0) {
            max_result = max(arr[i], max_result * arr[i]);
            min_result = min(arr[i], min_result * arr[i]);
            result = result > max_result ? result : max_result;
        } else if (arr[i] < 0) {
            int min_temp = min_result;
            int max_temp = max_result;
            min_result = min(arr[i], max_temp * arr[i]);
            max_result = max(arr[i], min_temp * arr[i]);
            result = result > max_result ? result : max_result;
        } else {
            result = result > 0 ? result : 0;
        }
    }
    return result;
}

int main () {
    vector<int> arr {2, 3, -2, 4, -1};
    cout << find_maximum_product(arr) << endl;

}
