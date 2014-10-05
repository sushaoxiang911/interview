#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > get_subsets(vector<int> num) {
    vector<vector<int> > result;
    vector<int> subset;
    result.push_back(subset);
    if (num.empty())
        return result;
    
    for (int i = 0; i < num.size(); ++i) {
        int current_num = num[i];
        int current_size = result.size();
        for (int j = 0; j < current_size; ++j) {
            vector<int> temp = result[j];
            temp.push_back(current_num);
            result.push_back(temp);
        }
    }
    return result;
}

int main() {
    vector<int> num {1, 2, 3};
    vector<vector<int> > result = get_subsets(num);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
