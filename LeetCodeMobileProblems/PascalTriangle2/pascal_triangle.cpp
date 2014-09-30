#include <iostream>
#include <vector>

using namespace std;


// update the vector from back to front

vector<int> get_row(int row_index) {
    vector<int> result(row_index + 1, 0);
    result[0] = 1;
    for (int i = 1; i <= row_index; ++i) {
        for (int j = i; j >= 0; --j) {
            if (j == 0)
                result[j] = result[j];
            else if (j == i)
                result[j] = result[j-1];
            else
                result[j] = result[j] + result[j-1];
        }
    }
    return result;
}

int main() {
    cout << "result: " << endl;
    vector<int> result = get_row(4);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}
