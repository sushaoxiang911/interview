#include <iostream>
#include <vector>

using namespace std;

// dp
// dp[i] represents the max sum of subarray that end with i 

int find_max(vector<int> arr) {
    
    if (arr.empty())
        return 0;
    int max_sum = 0;
    vector<int> dp(arr.size(), 0);
    dp[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (dp[i-1] > 0)
            dp[i] = dp[i-1] + arr[i];
        else
            dp[i] = arr[i];
        if (dp[i] > max_sum)
            max_sum = dp[i];
    }
    return max_sum;
}

int main() {
    vector<int> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "result: " << find_max(arr) << endl;
}
