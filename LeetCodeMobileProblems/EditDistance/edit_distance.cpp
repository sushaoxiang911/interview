#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp
// dp[i][j] represents string1 from 1 to i change the string2 from 1 to j
// the minimum steps to do that
// consider there are three kinds of operations, insert, delete and modify
// dp[i][j] = min{dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+f(x[i],y[j])}
// f(x[i],y[j])=1 if x[i]!=y[j]; f(x[i],y[j])=0 if x[i]==y[j]

// dp[i-1][j]+1 means we first delete x[i] and then use x[0...i-1] to generate y[0...j]
// dp[i][j-1]+1 means we first change x[0...i] to y[0...j-1] and then add y[j]
// dp[i-1][j-1]+f(x[i],y[j]) means we first change x[0...i-1] to y[0...j-1] and 
// for the last char x[i] and y[j], we consider if we need a modification operation to do

//     a b c e
//   0 1 2 3 4
// e 1 1 2 3 3
// b 2 2 1 2 3
// c 3 3 2 1 2


int edit_distance (string word1, string word2) {
    // initilize with change empty to empty
    // empty to word2
    // word1 to empty
    int row = word1.size() + 1;
    int col = word2.size() + 1;

    vector<vector<int> > dp (row, vector<int>(col));
    
    // initalize
    for (int i = 0; i < col; ++i)
        dp[0][i] = i;
    for (int i = 0; i < row; ++i)
        dp[i][0] = i;
    
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            int deletion_step = dp[i-1][j] + 1;
            int insertion_step = dp[i][j-1] + 1;
            int modification_step = word1[i-1] == word2[j-1] ?
                                        dp[i-1][j-1] : dp[i-1][j-1] + 1;
            int min_step = deletion_step;
            if (insertion_step < deletion_step)
                min_step = insertion_step;
            if (modification_step < min_step)
                min_step = modification_step;
            dp[i][j] = min_step;
        }
    }
    return dp[word1.size()][word2.size()];
}

int main () {
    string word1 = "ebc";
    string word2 = "abce";
    cout << "result: " << edit_distance (word1, word2) << endl;
}



