#include <iostream>
#include <string>

using namespace std;

// O(n^2)
// check all the substrings, and find the longest substring that has no repeating characters


int longest_substring(string str) {
     if (str.size() == 0)
        return 0;
    
    int result = 0;
    // a map of characters
    // which indicate the first occurance of that characters
    int index_map[256] = {-1};
    for (int i = 0; i < str.size(); ++i) {
        int current_char = str[i];
        int start_index = index_map[current_char] + 1;
        int current_size = i - start_index + 1;
        if (current_size > result)
            result = current_size;
        index_map[current_char] = i;
    }

    return result;

}


int main() {
    string str = "bbbb";
    cout << "result: " << longest_substring(str) << endl;
}
