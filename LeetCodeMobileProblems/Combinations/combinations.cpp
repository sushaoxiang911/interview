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

int main() {
    vector<vector<int> > result = find_combinations(5, 2);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
