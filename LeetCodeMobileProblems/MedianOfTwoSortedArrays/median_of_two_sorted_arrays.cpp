#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


// every time, we choose the remain numbers in k, 
// and we get from arr1 k/2 and arr2 k/2
// and we definitely can ensure that half of the array is in the combination

int find_kth(vector<int> &arr1, vector<int> &arr2, int arr1_start, int arr2_start, int k) {
    if (arr1_start >= arr1.size())
        return arr2[arr2_start+k-1];
    if (arr2_start >= arr2.size())
        return arr1[arr1_start+k-1];
    if (k == 1)
        return min(arr1[0], arr2[0]);
    int arr1_remain_size = arr1.size() - arr1_start;
    int arr1_check_index = min(arr1_remain_size, k/2) + arr1_start - 1;
    int arr2_check_index = k - min(arr1_remain_size, k/2) + arr2_start - 1;
    if (arr1[arr1_check_index] > arr2[arr2_check_index]) {
        return find_kth(arr1, arr2, arr1_start, arr2_check_index + 1, 
                        min(arr1_remain_size, k/2));
    } else if (arr1[arr1_check_index] < arr2[arr2_check_index]) {
        return find_kth(arr1, arr2, arr1_check_index + 1, arr2_start,
                        k - min(arr1_remain_size, k/2));
    } else {
        return arr1[arr1_check_index];
    }
}


int find_median(vector<int> arr1, vector<int> arr2) {
    int total = arr1.size() + arr2.size();
    if (total % 2)
        return find_kth(arr1, arr2, 0, 0, total/2 + 1);
        
    else
        return (find_kth(arr1, arr2, 0, 0, total/2) + 
                find_kth(arr1, arr2, 0, 0, total/2 + 1)) / 2;
}

int main() {
    vector<int> arr1 {1, 3, 4, 5, 10};
    vector<int> arr2 {2, 5, 6, 8, 12, 14};
    cout << "result: " << find_median(arr1, arr2) << endl;
}
