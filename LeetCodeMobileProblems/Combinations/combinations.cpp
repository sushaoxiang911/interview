#include <iostream>
#include <vector>

using namespace std;

// C n k = C n-1 k-1 + C n-1 k
// dp

vector<vector<int> > find_combinations (int n, int k) {
    vector<vector<int> > result;
    if (k > n)
        return result;
    if (n == k) {
        vector<int> temp;
        for (int i = 1; i <= n; ++i) 
            temp.push_back(i);
        result.push_back(temp);
        return result;
    }
    if (k == 1) {
        for (int i = 1; i <= n; ++i) {
            vector<int> temp;
            temp.push_back(i);
            result.push_back(temp);
        }
        return result;
    }
    
    vector<vector<int> > result1 = find_combinations(n - 1, k - 1);
    vector<vector<int> > result2 = find_combinations(n - 1, k);
    for (int i = 0; i < result1.size(); ++i) {
        vector<int> temp = result1[i];
        temp.push_back(n);
        result.push_back(temp);
    }
    for (int i = 0; i < result2.size(); ++i) {
        result.push_back(result2[i]);
    }
    return result;
}
// We can also use the thought from find all subsets of a set of numbers
// that is the combinations of k are also included in the subsets
// only we need to set up a guard to say that
// out results contains k number and put it into the result
void dfs (vector<vector<int> > &result, vector<int> &current_result, 
            int n, int start, int current_k, int k) {
    if (current_k == k) {
        result.push_back(current_result);
        return;
    }
    for (int i = start; i <= n - (k - current_k); ++i) {
        current_result.push_back(i+1);
        dfs(result, current_result, n, i + 1, current_k + 1, k);
        current_result.pop_back();
    }
}
vector<vector<int> > find_combinations_2(int n, int k) {
    vector<vector<int> > result;
    vector<int> current_result;
    dfs(result, current_result, n, 0, 0, k);
    return result;
}
// iteration
// use the subset to do that
// if the current set is already k size, then stop expanding it 
vector<vector<int> > find_combinations_3(int n, int k) {
    vector<vector<int> > result;
    vector<vector<int> > expand;
    vector<int> current;
    expand.push_back(current);
    for (int i = 0; i < n; i++) {
        int expand_size = expand.size();
        int current_num = i + 1;
        for (int j = 0; j < expand_size; ++j) {
            vector<int> expand_node = expand[j];
            expand_node.push_back(current_num);
            if (expand_node.size() == k)
                result.push_back(expand_node);
            else
                expand.push_back(expand_node);
        }
    }
    return result;
}





int main() {
    vector<vector<int> > result = find_combinations_3(5, 2);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
