#include <iostream>

using namespace std;

bool palindrome_number(int num) {
    
    if (num < 0)
        return false;
    if (num < 10)
        return true;
    int base = 10;
    while (num / base > 10) {
        base = base * 10;
    }
    int first_digit = num / base;
    int last_digit = num % 10;
    int remain = (num % base) / 10;
    return (first_digit == last_digit) && palindrome_number(remain);
}

int main() {
    cout << "result: " << palindrome_number(23322) << endl;
}
