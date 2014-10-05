#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_valid_palindrome(string str) {
    if (str == "")  
        return true;
    
    int start = 0;
    int end = str.size() - 1;
    while (start <= end) {
        while (str[start] < 'A' || (str[start] > 'Z' && str[start] < 'a') || 
                str[start] > 'z')
            ++start;
        while (str[end] < 'A' || (str[end] > 'Z' && str[end] < 'a') || 
                str[end] > 'z')
            --end;
        if (str[start] != str[end] && abs(str[start] - str[end]) != 32) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main() {
    string str = "race a car";
    cout << "result: " << is_valid_palindrome(str) << endl;
}
