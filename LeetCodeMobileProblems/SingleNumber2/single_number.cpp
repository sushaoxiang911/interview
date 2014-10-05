#include <iostream>
#include <vector>

using namespace std;


int find_single(vector<int> arr) {
    int result = 0;
    for (int i = 31; i >= 0; --i) {
        int window = 1 << i;
        int digit_sum = 0;
        for (int j = 0; j < arr.size(); ++j) {
            int current_digit = window & arr[j];
            digit_sum += (current_digit >> i);
        }
        cout << "i: " << i << endl;
        cout << "digit_sum: " << digit_sum << endl;
        int result_digit = digit_sum % 3;
        result = result + (result_digit << i);
    }
    return result;
}

int main() {
    vector<int> arr {1, 2, 2, 1, 3, 1, 4, 3, 3, 2};
    cout << "result: " << find_single(arr) << endl;
}
