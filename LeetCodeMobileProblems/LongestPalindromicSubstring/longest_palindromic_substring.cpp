#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp
// dp[i][j] represents if the string starts from j, end to i is a palindrome
// then we have dp[i+1][i] is true if  s[i+1] == s[i]
//              dp[i][j] is true if s[j] == s[i] && dp[i-1][j+1]

//   c b b a b b a
// c 1 0 0 0 0 0 0
// b 0 1 0 0 0 0 0
// b 0 1 1 0 0 0 0
// a 0 0 0 1 0 0 0
// b 0 0 1 0 1 0 0
// b 0 1 0 0 1 1 0
// a 0 0 0 1 0 0 1



string longest_palindromic_substring(string str) {
    vector<vector<bool> > dp(str.size(), vector<bool> (str.size(), false));
    int longest_length = 1;
    int longest_start = 0;
    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < str.size(); ++j) {
            if (i == j) {
                dp[i][j] = true;
                break;
            }
            if (i == j + 1 && str[i] == str[j]) {
                dp[i][j] = true;
                if (longest_length < 2) {
                    longest_length = 2;
                    longest_start = j;
                }
            }
            if (dp[i-1][j+1] && str[i] == str[j]) {
                dp[i][j] = true;
                if (i - j > longest_length) {
                    longest_length = i - j + 1;
                    longest_start = j;
                }
            }
        }
    }
    return str.substr(longest_start, longest_length);
}

string longest_palindromic_substring_2 (string str) {
    string result = str.substr(0, 1);
    int result_length = 1;
    for (int i = 0; i < str.size(); ++i) {
        int left_index = i - 1;
        int right_index = i + 1;
        while (left_index >= 0 && right_index < str.size() && 
            str[left_index] == str[right_index]) {
            left_index--;
            right_index++;
        }
        
        if (right_index - left_index - 1 > result_length) {
            result_length = right_index - left_index - 1;
            result = str.substr(left_index + 1, result_length);
        }
        left_index = i;
        right_index = i + 1;
        while (left_index >= 0 && right_index < str.size() &&
            str[left_index] == str[right_index]) {
            left_index--;
            right_index++;
        }
        if (right_index - left_index - 1 > result_length) {
            result_length = right_index - left_index - 1;
            result = str.substr(left_index + 1, result_length);
        }
    }
    return result;
}


// O(n) algorithm
// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
// http://www.felix021.com/blog/read.php?2040




int main() {
    string str = "cbbabba";
    cout << "result: " << longest_palindromic_substring(str) << endl;
    cout << "result: " << longest_palindromic_substring_2(str) << endl;
}

