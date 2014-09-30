#include <iostream>
#include <vector>

using namespace std;


vector<int> plus_one(vector<int> digits) {
    vector<int> result;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        int part_sum = carry + digits[i];
        result.insert(result.begin(), part_sum % 10);
        carry = part_sum / 10;
    }
    if (carry > 0)
        result.insert(result.begin(), 1);
    return result;
}

int main() {
    vector<int> digits {1, 2, 9};
    vector<int> result = plus_one(digits);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;

}

