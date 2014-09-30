#include <iostream>
#include <string>

using namespace std;



string integer2roman (int num) {
    string result;
    int digit = num % 10;
    num = num / 10;
    int tens_digit = num % 10;
    num = num / 10;
    int hundred_digit = num % 10;
    num = num / 10;
    int thousand_digit = num % 10;
    
    // thousand_digit
    for (int i = 0; i < thousand_digit; ++i)
        result.append("M");


    if (hundred_digit <= 3) {
        for (int i = 0; i < hundred_digit; ++i)
            result.append("C");
    } else if (hundred_digit > 3 && hundred_digit <= 5) {
        int temp = 5 - hundred_digit;
        for (int i = 0; i < temp; ++i)
            result.append("C");
        result.append("D");
    } else if (hundred_digit > 5 && hundred_digit < 9) {
        int temp = hundred_digit - 5;
        result.append("D");
        for (int i = 0; i < temp; ++i) 
            result.append("C");
    } else
        result.append("CM");

    if (tens_digit <= 3) {
        for (int i = 0; i < tens_digit; ++i)
            result.append("X");
    } else if (tens_digit > 3 && tens_digit <= 5) {
        int temp = 5 - tens_digit;
        for (int i = 0; i < temp; ++i)
            result.append("X");
        result.append("L");
    } else if (tens_digit > 5 && tens_digit < 9) {
        int temp = tens_digit - 5;
        result.append("L");
        for (int i = 0; i < temp; ++i) 
            result.append("X");
    } else
        result.append("XC");



    if (digit <= 3) {
        for (int i = 0; i < digit; ++i)
            result.append("I");
    } else if (digit > 3 && digit <= 5) {
        int temp = 5 - digit;
        for (int i = 0; i < temp; ++i)
            result.append("V");
        result.append("I");
    } else if (digit > 5 && digit < 9) {
        int temp = digit - 5;
        result.append("V");
        for (int i = 0; i < temp; ++i) 
            result.append("I");
    } else
        result.append("IX");

    return result;
}

int main () {

    cout << "result: " << integer2roman(1976) << endl;
}
