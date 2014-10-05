#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// O(nlogn)
// this is wrong!!! when sorting, index is different
vector<int> two_sum(vector<int> arr, int target) {
    vector<int> result;
    if (arr.size() == 0)
        return result;
    
    sort(arr.begin(), arr.end());
    
    int index1 = 0;
    int index2 = arr.size() - 1;
    while (index1 < index2) {
        int sum = arr[index1] + arr[index2];
        if (sum == target) {
            result.push_back(index1 + 1);
            result.push_back(index2 + 1);
            return result;
        }
        if (sum < target)
            ++index1;
        else
            --index2;
    }
    return result;
}

// O(n)
vector<int> two_sum_2(vector<int> arr, int target) {
    vector<int> result;
    if (arr.size() == 0)
        return result;
    map<int, int> m;
    for (int i = 0; i < arr.size(); ++i) {
        int other_num = target - arr[i];
        auto it = m.find(other_num);
        if (it == m.end()) {
            m.insert(pair<int, int>(arr[i], i));
        } else {
            result.push_back(it -> second + 1);
            result.push_back(i + 1);
            return result;
        }
    }   
}


int main() {
    vector<int> arr{11, 7, 2, 15};
    vector<int> result = two_sum_2(arr, 9);
    cout << "result: " << result[0] << " " << result[1] << endl;

}

