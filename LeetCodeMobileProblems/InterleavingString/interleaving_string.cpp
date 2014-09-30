#include <iostream>
#include <string>
#include <vector>

using namespace std;

// it is a dp
// given a state of n of string1 and m of string2 is interleaving, we can check
// n+1 of string1 and m of string2... dynamic programming

// s1 = "aabcc"
// s2 = "dbbca"
// s3 = "aadbbcbcac"

//     a a b c c
//   1 1 1 0 0 0
// d 0 0 1 1 0 0
// b 0 0 1 1 1 0
// b 0 0 1 0 1 1
// c 0 0 1 1 1 0
// a 0 0 0 0 1 1


bool ckeck_interleaving (string s1, string s2, string s3) {
    int s1_size = s1.size();
    int s2_size = s2.size();
    int s3_size = s3.size();
    if (s1_size + s2_size != s3_size)
        return false;
    int col = s1_size + 1;
    int row = s2_size + 1;

    vector<vector<bool> > dp (row, vector<bool> (col, false));
    dp[0][0] = true;

    for (int i = 1; i < col; ++i) {
        if (s1[i-1] == s3[i-1] && dp[0][i-1])
            dp[0][i] = true;
    }
    
    for (int i = 1; i < row;  ++i) {
        if (s2[i-1] == s3[i-1] && dp[i-1][0])
            dp[i][0] = true;
    }

// be sure that what i indicates, what j indicates 
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if ((dp[i-1][j] && s2[i-1] == s3[i+j-1]) ||
                    (dp[i][j-1] && s1[j-1] == s3[i+j-1]))
                dp[i][j] = true;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[row-1][col-1];
}


int main () {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << "result: " << ckeck_interleaving(s1, s2, s3) << endl;
}

