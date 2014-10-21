#include <iostream>
#include <vector>

using namespace std;
// it is for every element, we add it into the former one
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


// DFS
// that is for every element, we find all the 
// set that contains it. 
void dfs(vector<int> &num, 
        vector<vector<int> > &result, vector<int> &current_depth, int start){
    for (int i = start; i < num.size(); ++i) {
        current_depth.push_back(num[i]);
        result.push_back(current_depth);
        dfs(num, result, current_depth, i + 1);
        current_depth.pop_back();
    }
    
}

vector<vector<int> > get_subsets_2(vector<int> num) {
    vector<vector<int> > result;
    vector<int> current_depth;
    result.push_back(current_depth);
    dfs(num, result, current_depth, 0);
    return result;   
}



int main() {
    vector<int> num {1, 2, 3};
    vector<vector<int> > result = get_subsets_2(num);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
