#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_permutation(int k, int n) {
    string result(n, '0');
    // here since we are using n!, we can calculate a vector in advance
    vector<int> factorial(n + 1, 0);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i-1] * i;

    vector<bool> record(n, false);
    
    int current_order = 0;
    for (int i = 1; i <= n; ++i) {
        int digit_option = n - i + 1;
        int digit_remain = n - i;
        for (int j = digit_option; j >= 1; --j) {
            int current_accumulation = factorial[digit_remain] * (j - 1) + 1;
            if (current_order + current_accumulation <= k) {

                cout << "j: " << j << endl;
                int temp_id = j;
                int temp = 1;
                for (int k = 0; k < n; ++k) {
                    if (record[k])
                        continue;
                    else {
                        if (temp == temp_id) {
                            record[k] = true;
                            result[i - 1] =  (k + 1) + '0';
                            break;
                        }
                        temp++;
                    }
                }
                current_order = current_order + current_accumulation - 1;
                break;
            }
        }
    }
    return result;
}


int main() {
    cout << "result: " << get_permutation (6, 3) << endl;
}
