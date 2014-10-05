#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int> > get_subsets(vector<int> num) {
    vector<vector<int> > result;
    vector<int> subset;
    result.push_back(subset);
    if (num.empty())
        return result;
    
    sort(num.begin(), num.end());
    int current_num = INT_MIN;
    int same_count = 0;
    for (int i = 0; i < num.size(); ++i) {
        if (num[i] != current_num) {
            current_num = num[i];
            same_count = 1;
        } else 
            ++same_count;
        
        int current_size = result.size();
        for (int j = 0; j < current_size; ++j) {
            vector<int> temp = result[j];
            if (temp.empty() && same_count > 1)
                continue;
            int check_index = temp.size() - same_count + 1;
            if (check_index < 0 || check_index >= temp.size() || 
                    temp[check_index] == current_num) {
                temp.push_back(current_num);
                result.push_back(temp);
            }
        }
    }
    return result;
}

int main() {
    vector<int> num {1, 2, 2};
    vector<vector<int> > result = get_subsets(num);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) 
            cout << result[i][j] << " ";
        cout << endl;
    }
}
