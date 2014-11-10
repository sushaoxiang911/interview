#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> arr) {

    vector<int> dp(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        int current = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                int temp = dp[j] + 1;
                if (temp > current)
                    current = temp;
            }
            dp[i] = current;
        }
    }
    int result = dp[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}

int main() {
    vector<int> arr {4, 0, 3, 1, 2, 1};
    cout << "result: " << lis(arr) << endl;
}
