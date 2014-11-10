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
            // here every time we increment i by 1
            // so we decrement digit_remain by 1
            // no vector needed
            int current_accumulation = factorial[digit_remain] * (j - 1) + 1;
            if (current_order + current_accumulation <= k) {

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


// we only need to know the index of the digit that we will pick for every time
// that is if we 1256 in our candidates, if we choose 5 as the first
// then our candidates have 126 which is in order and can be directly used in next
// iteration
//
string get_permutation_2(int k, int n) {
    vector<int> candidates;
    int permutation_count = 1;
    for (int i = 0; i < n; i++) {
        candidates.push_back(i + 1);
        permutation_count *= (i + 1);
    }

    // start with 0
    k--;

    string result = "";
    for (int i = 0; i < n; ++i) {
        int digit_choice = n - i;
        permutation_count /= digit_choice;
        int choose_digit_index = k / permutation_count;
        result += ('0' + candidates[choose_digit_index]);
        // update the candidate vector
        for (int j = choose_digit_index; j < n - i - 1; ++j) {
            candidates[j] = candidates[j+1];
        }
        k %= permutation_count;
    }
    return result;
}


int main() {
    cout << "result: " << get_permutation(6, 3) << endl;
    cout << "result: " << get_permutation_2 (6, 3) << endl;
}
