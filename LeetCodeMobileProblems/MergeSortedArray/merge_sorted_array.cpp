#include <iostream>

using namespace std;

void merge_array (int arr1[], int arr2[], int n, int m) {
    int total_size = m + n;
    
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
            k--;
        } else if (arr1[i] < arr2[j]) {
            arr1[k] = arr2[j];
            j--;
            k--;
        } else {
            arr1[k] = arr2[j];
            k--;
            arr1[k] = arr2[j];
            k--;
            i--;
            j--;
        }
    }
    while (j >= 0) {
        arr1[k] = arr2[j];
        k--;
        j--;
    }
}

int main() {
    int* arr1 = new int[7];
    int* arr2 = new int[3];
    arr1[0] = 1;
    arr1[1] = 3;
    arr1[2] = 7;
    arr1[3] = 10;
    arr2[0] = 2;
    arr2[1] = 5;
    arr2[2] = 6;
    merge_array(arr1, arr2, 4, 3);
    for (int i = 0; i < 7; ++i)
        cout << arr1[i] << " ";
    cout << endl;
}
