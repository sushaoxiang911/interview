#include <iostream>
#include <vector>

using namespace std;
// actually constant memory is enough for this problem
int find_max_2(vector<int> arr) {
    if (arr.empty())
        return 0;
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        current_sum = arr[i] > current_sum + arr[i] ? arr[i] : current_sum + arr[i];
        if (current_sum > max_sum)
            max_sum = current_sum;
    }
    return max_sum;
}

int main() {
    vector<int> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "result: " << find_max_2(arr) << endl;
}
