#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;


// this one is beyond the time limit

bool is_palindrome(string str) {
    int first = 0;
    int last = str.size() - 1;
    while (first <= last) {
        if (str[first] != str[last]) {
            break;
        } else {
            first++;
            last--;
        }
    }
    return (first > last);
}

void partitioning(int &result, string str,
                    int path) {
    for (int i = 0; i < str.size(); ++i) {
        string current_partition = str.substr(0, i + 1);
        string remain = str.substr(i + 1);
        if (is_palindrome(current_partition)) {
            ++path;
            if (is_palindrome(remain)) {
                if (remain.size() != 0)
                    ++path;
                if (path < result)
                    result = path;
                if (remain.size() != 0)
                    --path;
            } else {
                partitioning(result, remain, path);
            }
            --path;
        }
    }

}

int palindrome_partitioning(string str) {
    int result = str.size();
    partitioning(result, str, 0);
    return result;
}

// another way is use a dp grid
// for palindrome consider the dp grid
// dp[i][j] represents that if str[j...i] is a palindrome or not
// in this problem, we consider another array count[]
// count[j] reprensents the minimum palindrome partition of the string from j
// so for the count[j], we have
// if (dp[i][j]) 
// count[j] min{count[j], 1 + count[i+1]}

// remember palindrome grid
//         i ->
//        a b a b
// j|   a 1 0 0 0
//  V   b 0 1 0 0
//      a 1 0 1 0
//      b 0 1 0 1


int palindrome_partitioning_2(string str) {
    int size = str.size();
    vector<vector<bool> > dp(size, vector<bool> (size, false));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (str[i] == str[j] && (i - j < 2 || dp[i-1][j+1]))
                dp[i][j] = true;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) 
            cout << dp[i][j] << " ";
        cout << endl;
    }
    vector<int> count(size + 1, 0);
    count[size] = 0;
    for (int j = size - 1; j >= 0; --j) {
        count[j] = INT_MAX;
        for (int i = j; i < size; ++i) {
            if (dp[i][j]) {
                count[j] = min(count[j], count[i+1] + 1);
            }
        }
    }
    for (int i = 0; i < size + 1; i++) 
        cout << count[i] << " ";
    cout << endl;
    return count[0];
}






int main() {
    string str = "abab";
    cout << "result: " << palindrome_partitioning_2(str) << endl;
}
