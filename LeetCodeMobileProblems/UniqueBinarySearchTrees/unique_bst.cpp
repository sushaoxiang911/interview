#include <iostream>

using namespace std;


int unique_bst(int n) {
    if (n == 0)
        return 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (unique_bst(i) * unique_bst(n - 1 - i));
    }
    return sum;
}

int main() {
    cout << "result: " << unique_bst(0) << endl;
}
