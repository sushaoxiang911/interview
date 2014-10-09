#include <iostream>
#include <vector>

using namespace std;

// We can easily find the place that the middle part is not sorted

// and the first part is ascending and the last part is descending
// we then know that the middle part should be merged into these two parts

// so if we can find the range of the middle part and the minimum value of middle part
// i.e. the left start of middle part
// we can find where it should begin in the first part
// same for the maximum value of middle part


int find_index(vector<int> arr) {
    if (arr.empty()) {
        return -1;
    }
    // find the increasing first part
    int first_end = -1;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i-1]) {
            first_end = i;
            break;
        }
    }

    if (first_end == -1)
        return 0;

    // find the increasing last part
    int last_start = arr.size() - 1;
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (arr[i] > arr[i+1]) {
            last_start = i;
            break;
        }
    }
    int sort_start = 0;
    int sort_end = 0;
    

    // find the min and max of the middle part;
    int middle_min = arr[first_end];
    int middle_max = arr[first_end];
    for (int i = first_end; i <= last_start; ++i) {
        if (arr[i] > middle_max)
            middle_max = arr[i];
        if (arr[i] < middle_min)
            middle_min = arr[i];
    }
    
    for (int i = 0; i < first_end; ++i) {
        if (middle_min < arr[i]) {
            sort_start = i;
            break;
        }
    }
    for (int i = last_start + 1; i < arr.size(); ++i) {
        if (middle_max < arr[i]) {
            sort_end = i;
            break;
        }
    }
    return sort_end - sort_start;

}

int main() {
    vector<int> arr{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    cout << "result: " << find_index(arr) << endl; 
}
