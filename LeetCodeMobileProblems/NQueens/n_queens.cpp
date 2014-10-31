#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// first permutation all the result
// 0...n-1 permutations
// a vector<int> perm(n), perm[i] respresents the Q on the row i col perm[i]
// and we check the condition


// one cannot prune in advance
// we only achieve the index == n that we can start to check
void n_queens_help(vector<vector<string> > &result, int n,
                    vector<int> current_permutation, int index) {
    if (index == n) {
        bool flag = true;
        for (int i = 0; i < current_permutation.size(); ++i) {
            for (int j = i + 1; j < current_permutation.size(); ++j) {
                if (abs(current_permutation[j] - current_permutation[i])
                        == abs(j - i)) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            vector<string> sol;
            for (int i = 0; i < n; ++i) {
                string current_row(n, '.');
                int current_position = current_permutation[i];
                current_row[current_position] = 'Q';
                sol.push_back(current_row);
            }
            result.push_back(sol);
        }
        return;
    }
    int new_size = current_permutation.size() + 1;
    for (int i = 0; i < new_size; ++i) {
        vector<int> new_permutation;
        for (int j = 0; j < i; ++j) {
            new_permutation.push_back(current_permutation[j]);
        }
        new_permutation.push_back(index);
        for (int j = i; j < current_permutation.size(); ++j) {
            new_permutation.push_back(current_permutation[j]);
        }
        n_queens_help(result, n, new_permutation, index + 1);
    }
}


vector<vector<string> > n_queens (int n) {
    vector<vector<string> > result;
    vector<int> permutation;
    permutation.clear();
    n_queens_help(result, n, permutation, 0);
    return result;
}

void n_queens_2_help(vector<vector<string> > &result, int n,
            vector<int> &current_result, int index) {
    if (index != 0) {
        int last_pos = current_result[n-1];
        for (int i = 0; i < n - 1; ++i) {
            if (current_result[i] == last_pos ||
                    abs(current_result[i] - last_pos) == abs(i - (n-1)))
                return;
        }
    }

    if (index == n) {
        vector<string> sol;
        for (int i = 0; i < n; ++i) {
            string current_row(n, '.');
            int current_position = current_result[i];
            current_row[current_position] = 'Q';
            sol.push_back(current_row);                                       
        }
        result.push_back(sol);
        return;
    }
    for (int i = 0; i < n; ++i) {
        current_result.push_back(i);
        n_queens_2_help(result, n, current_result, index + 1);
        current_result.pop_back();
    } 
}

vector<vector<string> > n_queens_2 (int n) {
    vector<vector<string> > result;
    vector<int> current_result;
    current_result.clear();
    n_queens_help(result, n, current_result, 0);
    return result;
}



int main() {
    vector<vector<string> > result = n_queens_2(4);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) 
            cout << result[i][j] << endl;
        cout << endl;
        cout << endl;
    }
    
}




