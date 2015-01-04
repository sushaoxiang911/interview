#include <iostream>

using namespace std;

int tailing_zeros(int n) {
    // we need to find how many 5 we have from 1 to n
    // so we count 5
    // 5 * 5
    // 5 * 5 * 5
    int result = 0;
    while (n >= 1) {
        result += (n / 5);
        n /= 5;
    }
    return result;
}

int main() {
    cout << tailing_zeros(25) << endl;
}

