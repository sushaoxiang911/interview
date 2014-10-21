#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char notation (int num) {
    if (num > 9) {
        return (num - 10 + 'a');
    } else 
        return num + '0';
}


vector<char> convert(int num, int base) {
    
    vector<char> result;
    if (base > 36)
        return result;
    while (num != 0) {
        int current_digit = num % base;
        result.push_back(notation(current_digit));
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
} 

int main() {
    vector<char> result = convert(3000, 12);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}
