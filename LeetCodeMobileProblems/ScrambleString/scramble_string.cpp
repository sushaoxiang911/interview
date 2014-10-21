#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_scramble(string s1, string s2) {
    if (s1 == s2)
        return true;
 
    for (int i = 0; i < s1.size() - 1; ++i) {
        if ((is_scramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) 
                && is_scramble(s1.substr(i + 1), s2.substr(i + 1))) ||
            (is_scramble(s1.substr(0, i + 1), s2.substr(s1.size() - i - 1))
                && is_scramble(s1.substr(s1.size() - i - 1), s2.substr(0, i + 1))))
            return true;
    }
    return false;
}



// dp
// dp[i][j][k] represents that s1[i ... i+k-1] and s2[j ... j+k-1] is scramble string or not
// first condition: k = 1
// dp[i][j][1] = (s1[i] == s2[j])

// second conditon: k = 2
// dp[i][j][2] = (dp[i][j][1] && dp[i+1][j+1][1]) || (dp[i][j+1][1] && dp[i+1][j][1])
// AC is scramble with AC || AC is scramble with CA

// third considtion: with bigger k
// we cut it and check our dp matrix

// dp can be considered in more dimensions, making things easier even if we don't use everything
bool is_scramble_2(string s1, string s2) {
    if (s1 == "" && s2 == "")
        return true;
    if (s1.size() != s2.size())
        return false;
    int size = s1.size();
    vector<vector<vector<bool> > > dp
        (size, vector<vector<bool> > (size, vector<bool> (size + 1, false)));
    for (int k = 1; k <= size; ++k) {
        for (int i = 0; i <= size - k; ++i) {
            for (int j = 0; j <= size - k; ++j) {
                if (k == 1) {
                    dp[i][j][k] = (s1[i] == s2[j]);
                } else {
                    for (int l = 1; l < k; ++l) {
                        if ((dp[i][j][l] && dp[i+l][j+l][k-l]) || 
                            (dp[i][j+k-l][l] && dp[i+l][j][k-l])) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][size];
}



int main() {
    string s1 = "great";
    string s2 = "rgtae";

    cout << "result: " << is_scramble_2(s1, s2) << endl;

}
