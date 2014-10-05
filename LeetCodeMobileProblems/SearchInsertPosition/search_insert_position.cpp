#include <iostream>
#include <vector>

using namespace std;


int get_insertion(vector<int> arr, int target) {
    int begin = 0;
    int end = arr.size() - 1;
    
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (arr[mid] ==  target) {
            return mid;
        }
        if (arr[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return begin;
}

int main() {
    vector<int> arr {1, 3, 5, 6};
    cout << "result: " << get_insertion(arr, 0) << endl;
}
