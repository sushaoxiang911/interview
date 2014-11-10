#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// a = "BDCABA"
// b = "ABCBDAB"

//     B D C A B A
//   0 0 0 0 0 0 0
// A 0 0 0 0 1 1 1 
// B 0 1 1 1 1 2 2
// C 0 1 1 2 2 2 2 
// B 0 1 1 2 2 3 3 
// D 0 1 2 2 2 3 3
// A 0 1 2 2 3 3 4
// B 0 1 2 2 3 4 4 


int lcs(string a, string b) {
    vector<vector<int> > dp(b.size() + 1, vector<int> (a.size() + 1, 0));
    int row = b.size() + 1;
    int col = a.size() + 1;
    for (int i = 0; i < row; ++i)
        dp[i][0] = 0;
    for (int j = 0; j < col; ++j)
        dp[0][j] = 0;
    
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (b[i-1] == a[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[row-1][col-1];
}

int main() {
    string a = "BDCABA";
    string b = "ABCBDAB";
    cout << "result: " << lcs(a, b) << endl;
}
