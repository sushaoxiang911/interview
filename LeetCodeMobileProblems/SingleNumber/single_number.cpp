#include <iostream>
#include <vector>

using namespace std;

// use ^ here
// 1^1 = 0, 0^0=0, 1^0=1
// therefor, two same number with XOR will be a zero

// use map is very direct
int find_single(vector<int> arr) {
    int result = 0;
    for (int i = 0; i < arr.size(); ++i) 
        result ^= arr[i];
    return result;
}

int main() {
    vector<int> arr {1, 2, 4, 2, 4, 3, 1};
    cout << "result: " << find_single(arr) << endl;

}
