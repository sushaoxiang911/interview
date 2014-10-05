#include <iostream>
#include <vector>

using namespace std;


void sort_colors(vector<int> &arr) {
    int stats[3] = {0};
    for (int i = 0; i < arr.size(); ++i) 
        stats[arr[i]]++;
    for (int i = 0; i < arr.size(); ++i) {
        if (i < stats[0])
            arr[i] = 0;
        else if (i >= stats[0] && i < (stats[0] + stats[1]))
            arr[i] = 1;
        else
            arr[i] = 2;
    }   
}

int main() {
    vector<int> arr {1, 0, 2, 1, 0, 0, 0, 2, 2, 1, 1};
    sort_colors(arr);
    cout << "result: " << endl;
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}
