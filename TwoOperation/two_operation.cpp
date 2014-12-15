#include <iostream>


using namespace std;

// when handling big number, consider if we could use recursion
// what would be the biggest stack
// if it is reasonable like 100 levels
// feel good to use stack and if it can really save time
//
// in this problem, we can simply always jump half of the calculation
// never consider dp here

int find_min_op(long long num) {
    if (num == 1)
        return 1;
    if (num % 2) 
        return find_min_op(num - 1) + 1;
    else
        return find_min_op(num / 2) + 1;
}

int main() {
    long long num = 12324562543214;
    cout << "result: " << find_min_op(num) << endl;
}
