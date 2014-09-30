#include <iostream>

using namespace std;

int main(){
    int a = 5;
    int b = 7;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << "After switching" << endl;  
    cout << "a: " << a << endl; 
    cout << "b: " << b << endl;
    return 0;

}
