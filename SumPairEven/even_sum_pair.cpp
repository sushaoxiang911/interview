#include <iostream>
#include <vector>

using namespace std;

int even_pair(vector<int> arr) {
    // we know that even + even = even
    // odd + odd = odd
    int odd = 0;
    int even = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            sum += even;
            even++;
        } else {
            sum += odd;
            odd++;
        }
    }
    return sum;
} 

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 6};
    cout << "result: " << even_pair(arr) << endl;
}
