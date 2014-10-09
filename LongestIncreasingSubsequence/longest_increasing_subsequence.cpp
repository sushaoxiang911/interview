#include <iostream>
#include <vector>

using namespace std;



int longest_increasing_subsequence(vector<int> arr) {
    if (arr.empty())
        return 0;
    // use O(n^2)
    // dont think O(n^2) means we have to do a 2-D matrix
    // 2D matrix means our transition comes from later state
    // in string or vector dp
    // if it is 2D, typically dp[i][j] represents state of substr[i...j]
    
    // And in this problem, we don't need to keep track of the start point of subarray
    vector<int> dp(arr.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < arr.size(); ++i) {
        int temp = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (dp[j] + 1 > temp)
                    temp = dp[j] + 1;
            }
        }
        dp[i] = temp;
    }
    for (int i = 0; i < dp.size(); ++i)
        cout << dp[i] << " ";
    cout << endl;
    return dp[arr.size()-1];
}

int main() {
    vector<int> arr{1, 3, 2, 8, 5, 2, 6};
    cout << "result: " << longest_increasing_subsequence(arr) << endl;
}
