#include <iostream>
#include <vector>

using namespace std;


// if there is  no duplicate, we can always find the right halve to search

int search_in_rotated_help(vector<int> &arr, int start, int end, int target) {
    if (start > end)
        return -1;
    
    int mid = (start + end) >> 1;
    
    int mid_value = arr[mid];
    if (mid_value == target)
        return mid;
 
    if (target < mid_value && mid_value <= arr[end]) {
        return search_in_rotated_help(arr, start, mid - 1, target);
    }
    if (target > mid_value && mid_value >= arr[start]) {
        return search_in_rotated_help(arr, mid + 1, end, target);
    }
    
    if (target < mid_value && mid_value >= arr[start]) {
        if (target < arr[start]) 
            return search_in_rotated_help(arr, mid + 1, end, target);
        else
            return search_in_rotated_help(arr, start, mid - 1, target);
    }
    if (target > mid_value && mid_value <= arr[end]) {
        if (target > arr[end])
            return search_in_rotated_help(arr, start, mid - 1, target);
        else
            return search_in_rotated_help(arr, mid + 1, end, target);
    }
    
}

int search_in_rotated(vector<int> &arr, int target) {
    return search_in_rotated_help(arr, 0, arr.size() - 1, target);
}

// one can also do a linear search find the break place an do two binary search

int main() {
    vector<int> arr{4, 5, 6, 7, 0, 1, 2};
    cout << "result: " << search_in_rotated(arr, 3) << endl;
}
