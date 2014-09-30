#include <iostream>
#include <string>
#include <map>

using namespace std;

int roman_to_integer(string roman) {
    if (roman == "") 
        return 0;  

    map <char, int> m;  
    m['I'] = 1; 
    m['V'] = 5; 
    m['X'] = 10; 
    m['L'] = 50; 
    m['C'] = 100; 
    m['D'] = 500; 
    m['M'] = 1000;

    int i = roman.size() - 1;
    char current_char = roman[i];
    int sum = m[current_char];
    --i;
    while (i >= 0) {
        char current_char = roman[i];
        char next_char = roman[i+1];
        if (m[next_char] > m[current_char])  
            sum -= m[current_char];
        else  
            sum += m[current_char];
        --i;
    }
    return sum;  
}

int main() {
    string roman = "VII";
    cout << "result: " << roman_to_integer(roman) << endl;
}
