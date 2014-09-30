#include <iostream>
#include <string>
#include <vector>

using namespace std;

string find_prefix (vector<string> words) {
    // find the small length of comparison
    int min_len = -1;
    for (int i = 0; i < words.size(); ++i) {
        if (min_len < 0)
            min_len = words[i].size();
        if (words[i].size() < min_len)
            min_len = words[i].size();
    }

    if (min_len == 0)
        return "";
    
    string result = words[0];
    for (int i = 1; i < words.size(); ++i) {
        string current = words[i];
        string temp;
        for (int j = 0; j < min_len; j++) {
            if (j >= result.size() || j >= current.size())
                break;
            if (current[j] == result[j])
                temp += current[j];
            else {
                result = temp;
                break;
            }
        }
    }
    return result;
}


int main() {
    vector<string> words {"abcde", "abcd", "abce"};
    cout << find_prefix(words) << endl;

}

