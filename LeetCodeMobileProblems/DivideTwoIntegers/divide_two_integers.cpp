#include <iostream>
#include <cstdlib>

using namespace std;
// minus the divisor one by one
// time limit
// every time makes the sum to be the twice
// and count to be the twice

int divide(int dividend, int divisor) {
    if (dividend == 0 || divisor == 0)
        return 0;

    bool neg = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        neg = true;
    
    long long c = dividend;
    long long d = divisor;
    long long a = abs(c);
    long long b = abs(d);

    if (b > a)
        return 0;
    long long sum = 0;
    int count = 0;
    int final = 0;
// use two loops to do that
// inside every time double
// outside to reserve the leftover
    while (a >= b) {
        count = 1;
        sum = b;
        while (sum + sum <= a) {
            sum += sum;
            count += count;
        }
        a -= sum;
        final += count;
    }
    if (neg)
        final = -final;
    return final;
}

int main () {
    int dividend = 2147483647;
    int divisor = 2;
    cout << divide(dividend, divisor) << endl;
}
