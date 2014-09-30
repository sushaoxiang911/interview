#include <iostream>
#include <string>
#include <vector>

using namespace std;

// as the longest subsequence problem
// use two demension dp
// O(m*n)

// dp[i][j] represents the number of subsequences in S[0...j-1] that is same with T[0...i-1]
// then we have
// if T[i] == S[j], f[i+1][j+1] = f[i][j] + f[i+1][j]
// if T[i] != S[j], f[i+1][j+1] = f[i+1][j]

// subsequence problem, consider dp
// dp comes from the transfer function
// how subseqente state comes from the previous state
int distinct_subsequences(string s, string t) {
    
    // the init should be
    //    a r a b i t
    //  1 1 1 1 1 1 1
    //r 0 0 1 1 1 1 1 
    //a 0
    //b 0
    //i 0
    //t 0     

    vector<int> temp(s.size()+ 1, 0);
    vector<vector<int> > dp(t.size() + 1, temp);
    for (int j = 0; j < s.size() + 1; ++j)
        dp[0][j] = 1;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (t[i] == s[j])
                dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
            else
                dp[i+1][j+1] = dp[i+1][j];
        }
    }
    return dp[t.size()][s.size()];
}

int main() {
    string t = "rabit";
    string s = "rababbit";
    cout << "result: " << distinct_subsequences(s, t) << endl;
    
}
