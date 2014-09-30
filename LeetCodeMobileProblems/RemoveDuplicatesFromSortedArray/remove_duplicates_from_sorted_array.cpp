#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates_i(int arr[], int size) {
    if (size == 0)
        return 0;
    
    int new_tail = 1;
    int old_tail = 1;
    int duplicate = 0;
    while (old_tail < size) {
        if (arr[old_tail] == arr[old_tail-1]) {
            old_tail++;
            duplicate++;
        } else {
            arr[new_tail] = arr[old_tail];
            new_tail++;
            old_tail++;
        }
    }
    return size - duplicate;
}

int remove_duplicates_ii(int arr[], int size) {
    if (size == 0)
        return 0;
    
    int new_tail = 1;
    int old_tail = 1;
    int duplicate = 0;
    while (old_tail < size) {
        if (old_tail > 1 && 
                arr[old_tail] == arr[old_tail-duplicate-1] && 
                arr[old_tail] == arr[old_tail-duplicate-2]) {
            old_tail++;
            duplicate++;
        } else {
            arr[new_tail] = arr[old_tail];
            new_tail++;
            old_tail++;
        }
    }
    return size - duplicate;
}



int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    int size = remove_duplicates_i(arr, 6);
    cout << "result 1: " << endl;
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {1, 1, 1, 2, 2, 2, 3};
    size = remove_duplicates_ii(arr2, 7);
    cout << "result 2: " << endl;
    for (int i = 0; i < size; ++i)
        cout << arr2[i] << " ";
    cout << endl;
}
