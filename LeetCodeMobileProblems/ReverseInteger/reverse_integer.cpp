#include <iostream>

using namespace std;

int reverse(int num) {
    
    bool neg = false;
    if (num < 0) {
        neg = true;
        num = -num;
    }

    int result = 0;
    while (num > 0) {
        int digit = num % 10;
        result = result * 10 + digit;
        num /= 10;
    }
    if (neg)
        result = -result;
    return result;

}

int main() {
    cout << "result: " << reverse(0) << endl;
}
