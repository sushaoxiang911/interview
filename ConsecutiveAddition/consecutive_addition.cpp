#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > find_consecutive(int num) {
    vector<vector<int> > result;
    if (num == 0)
        return result;

    int start = 1;
    int end = 1;
    while (end != num) {
        int temp_sum = (start + end) * (end - start + 1) / 2;
        if (temp_sum == num) {
            vector<int> current_result;
            for (int i = start; i <= end; ++i)
                current_result.push_back(i);
            result.push_back(current_result);
            end++;
        } else if (temp_sum < num)
            end++;
        else
            start++;
    }
    return result;
}

int main() {
    vector<vector<int> > result = find_consecutive(17);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
