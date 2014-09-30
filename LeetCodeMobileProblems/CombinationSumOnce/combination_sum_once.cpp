#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recursion (vector<vector<int> > &ans, vector<int> &candidates, vector<int> &num, int k,
    int sum, int target) {
    if (k >= candidates.size() || sum > target) 
        return;
    
    int current_can = candidates[k];
    int i = k;
    while (candidates[i] == current_can)
        ++i;
    
    recursion(ans, candidates, num, i, sum, target);
    
    num.push_back(current_can);
    sum += current_can;
    if (sum == target) {
        ans.push_back(num);
    }      
    recursion(ans, candidates, num, k+1, sum, target);
    num.pop_back();
}

vector<vector<int> > find_combination(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ans;
    vector<int> num;
    int sum = 0;
    recursion(ans, candidates, num, 0, sum, target);
    return ans;
}

int main() {
    vector<int> candidates {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int> > result = find_combination (candidates, 8);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    } 
}
