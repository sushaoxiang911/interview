#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// nlogn
// record the position and sort regard value
// and then the array becomes indices


struct arr_pair{
    int num;
    int pos;
};

// n
// find all the valid start points
// that is all the smallest from 0 to current position
int find_max_dis(vector<int> arr) {
    vector<arr_pair> start;
    // first loop
    int min_num = INT_MAX; 
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < min_num) {
            arr_pair temp {arr[i], i};
            start.push_back(temp);
            min_num = arr[i];    
        }
    }
   
    int result = 0;
    
    int cursor = arr.size() - 1;
    while (!start.empty()) {
        if (arr[cursor] > start.back().num) {
            int temp = cursor - start.back().pos;
            if (temp > result)
                result = temp;
            start.pop_back();
        } else
            cursor--;
    }
    
    return result;
}
int main() {
    vector<int> arr {4, 3, 5, 2, 1, 3, 2, 3};
    cout << "result: " << find_max_dis(arr) << endl;

}
