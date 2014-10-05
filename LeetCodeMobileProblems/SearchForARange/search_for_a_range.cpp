#include <iostream>
#include <vector>

using namespace std;

vector<int> search_range(vector<int> arr, int target) {
    vector<int> result;
    if (arr.empty())
        return result;
    
    // if we don't check equality inside we can always find the first number that we want
    // we would find the index that is one bigger than the index of element that just smaller
    // than the target
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
        int mid = (start + end) >> 1;   
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (arr[start] != target) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    int start_index = start;

    // still we need to find the first element that equals to
    start = 0;
    end = arr.size() - 1;
    while (start < end) {
        int mid = (start + end) >> 1;
        if (arr[mid] < target + 1)
            start = mid + 1;
        else
            end = mid - 1;
    }
    int end_index = start - 1;
    result.push_back(start_index);
    result.push_back(end_index);
    return result;
}

int main() {
    vector<int> arr{5, 7, 7, 8, 8, 10};
    vector<int> result = search_range(arr, 9);
    cout << "result: " << result[0] << " " << result[1] << endl;
}
