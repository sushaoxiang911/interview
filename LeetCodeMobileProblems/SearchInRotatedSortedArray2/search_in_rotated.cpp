#include <iostream>
#include <vector>

using namespace std;


int find_help(vector<int> &arr, int start, int end, int target) {
    
    if (start > end)
        return -1;
    int mid = (start + end) >> 1;
    int mid_value = arr[mid];
    if (target == mid_value)
        return mid;
    
    // left side is sorted and no duplicates
    if (arr[start] < arr[mid]) {
        if (target >= arr[start] && target <= arr[mid])
            return find_help(arr, start, mid - 1, target);
        else
            return find_help(arr, mid + 1, end, target);
    } else if (arr[start] > arr[mid]) {
        if (target >= arr[mid] && target <= arr[end])
            return find_help(arr, mid + 1, end, target);
        else
            return find_help(arr, start, mid - 1, target);
    } else {
        // we know that arr[start] == arr[mid]
        // and if arr[mid] == arr[end]
        // we cannot decide which halve to go
        if (arr[mid] == arr[end]) {
            int result = find_help(arr, start, mid - 1, target);
            if (result < 0)
                return find_help(arr, mid + 1, end, target);
            else
                return result; 
        // we know that left side is duplicates
        } else {
            return find_help(arr, mid + 1, end, target);
        }
    }
}

int search_in_rotated(vector<int> &arr, int target) {
    return find_help(arr, 0, arr.size() - 1, target);
}

int main() {
    vector<int> arr {4, 5, 6, 7, 8, 2, 3};
    cout << "result: " << search_in_rotated(arr, 6) << endl;
}
