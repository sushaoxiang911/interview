#include <iostream>

using namespace std;

int remove_element(int arr[], int size, int value) {
    if (size == 0)
        return 0;
    
    int new_index = 0;
    int old_index = 0;
    
    int eliminate = 0;
    while (old_index < size) {
        if (arr[old_index] == value) {
            old_index++;
            eliminate++;
        } else {
            arr[new_index++] = arr[old_index++];
        }
    }
    return size - eliminate;
}

int main() {
    int arr[] = {1, 3, 2, 4, 2, 3, 5};
    int size = remove_element(arr, 7, 2);
    cout << "result: " << endl;
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
