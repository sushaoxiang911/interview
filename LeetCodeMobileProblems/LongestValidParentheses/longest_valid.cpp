#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// dp is also very good to use
// it doesn't mean that if it is a one dimensional and we do a linear algorithm,
// it is greedy
// the key point is the state transition function, 
// if we can calculate state that we need with a O(1) time complexity, 
// then it is really linear algorithm and it is dp

// dp[i] represents the longest valid match starts from i
// so if the str[i] = ')', then no valid can starts with i and dp[i] is 0
//    if the str[i] = '(', then there might be something like (()())
//    dp[i] = 2 + dp[i+1] and we can calculate the paired ')' is 
//    j = i + 1 + dp[i+1]
//    there also might be something like ()(()())
//    that is after the paired ')' there is still a valid substring that followed

int get_longest(string str) {
    if (str.size() == 0)
        return 0;
    int result = 0;
    vector<int> dp(str.size(), 0);
    
    for (int i = str.size() - 2; i >= 0; --i) {
        if (str[i] == ')')
            dp[i] = 0;
        else {
            int pair_index = i + 1 + dp[i+1];
            if (pair_index < str.size() && str[pair_index] == ')') {
                int current_size = 2 + dp[i+1];
                if (pair_index + 1 < str.size())
                    current_size += dp[pair_index + 1];
                dp[i] = current_size;
                if (current_size > result)
                    result = current_size;
            } else
                dp[pair_index] = 0;
        }
    }
    return result;
}

// stack is direct way
// take invalid ')' as the delimiter
// that is the start of the valid pairing
// ()()() this we cannot get the start of the valid string
int get_longest_2(string str) {
    if (str.size() == 0)
        return 0;
    stack<int> s;
    int result = 0;
    // the index of the last invalid parenthese which is ')'    
    int last_invalid = -1;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(')
            s.push(i);
        else {
            if (s.empty()) 
                last_invalid = i;
            else {
                s.pop();
                int start_index;
                if (s.empty()) {
                    start_index = last_invalid + 1;    
                } else {
                    start_index = s.top() + 1;
                }
                int current_size = i - start_index + 1;
                if (current_size > result)
                    result = current_size;
            }
        }
    }
    return result;
}

int main() {
    string str = ")()())";
    cout << "result: " << get_longest_2(str) << endl;
}
