#include <iostream>
#include <vector>
#include <set>

using namespace std;



// use a hash table to do that
// consecutive traversal all the elements
int longest_length(vector<int> arr) {
    if (arr.empty())
        return 0;
    set<int> elements;
    for (int i = 0; i < arr.size(); ++i)
        elements.insert(arr[i]);

    int result = 1;

    for (int i = 0; i < arr.size(); ++i) {
        auto it = elements.find(arr[i]);
        if (it == elements.end())
            continue;
        int temp_result = 0;
        int temp_find = arr[i];
        while (it != elements.end()) {
            elements.erase(it);
            temp_result++;
            temp_find++;
            it = elements.find(temp_find);
        }
        
        temp_find = arr[i] - 1;
        it = elements.find(temp_find);
        while (it != elements.end()) {
            elements.erase(it);
            temp_result++;
            temp_find--;
            it = elements.find(temp_find);
        }
        if (temp_result > result)
            result = temp_result;
    }
    return result;
}

int main() {
    vector<int> arr {100, 4, 101, 200, 1, 3, 2};
    cout << "result: " << longest_length(arr) << endl;
}
