#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int b = 2;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a: " << a << " b: " << b << endl;
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a: " << a << " b: " << b << endl;

}
