#include <iostream>

using namespace std;

int swap_odd_even(int x) {
// 10101010101010101010101010101010 odd pos
// 01010101010101010101010101010101 even pos
    return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}

int main() {
    int a = swap_odd_even(1);
    cout << "result: " << a << endl;
}
