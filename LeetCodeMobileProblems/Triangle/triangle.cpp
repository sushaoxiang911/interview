#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int min_path_sum(vector<vector<int> > triangle) {
    if (triangle.empty())
        return 0;
    
    vector<int> dp(triangle.size(), 0);
    
    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = i; j >= 0; --j) {
            if (j == i && i > 0) {
                dp[j] = dp[j-1] + triangle[i][j];
                continue;
            }
            if (j > 0 && j < i) {
                dp[j] = (dp[j-1] <  dp[j] ? dp[j-1] : dp[j]) + triangle[i][j];
            }
            if (j == 0) {
                dp[j] = dp[j] + triangle[i][j];
            }
        }
    }
    int result = INT_MAX;
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] < result)
            result = dp[i];
    }
    return result;
}

int main() {
    vector<vector<int> > triangle{ {2},
                                  {3,4},
                                 {6,5,7},
                                {4,1,8,3}};
    cout << "result: " << min_path_sum(triangle) << endl;
}
