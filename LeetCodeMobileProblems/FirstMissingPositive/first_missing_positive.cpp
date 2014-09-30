#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

// consider use the original array to do that
// assume we have n array, from 0 to n-1
// then it should contains 1, 2, ..., n
// so we can do a mapping
// and use - to mark which number is existing
// that means we use the original array as our hash

// for the negative number or zero, we can use some way to makes them bigger than the N
// to mark as infinite

int first_missing_positive (vector<int> number) {
    // mark as infinite for all the non positive numbers
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] <= 0)
            number[i] = number.size() + 1;
    }

    for (int i = 0; i < number.size(); ++i) {
        int hash_index = abs(number[i]);
        if (hash_index <= number.size()) {
            if (number[hash_index-1] > 0)
                number[hash_index-1] = -number[hash_index-1];
        }
    }

    for (int i = 0; i < number.size(); ++i) {
        if (number[i] > 0)
            return i + 1;
    }
    
    return number.size() + 1;

}


int main() {
    vector<int> number {9, 7, 6, 5, 3, 1, 4, -5, 8, 4};
    cout << "result: " << first_missing_positive (number) << endl;
}
