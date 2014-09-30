#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map <vector<int>, vector<string> > classify_anagrams (vector<string> arr) {

    map<vector<int>, vector<string> > result;    

    for (int i = 0; i < arr.size(); ++i) {
        string current_string = arr[i];
        vector<int> char_record(256, 0);
        for (int j = 0; j < current_string.length(); ++j) {
            char current_char = current_string[j];
            char_record[(int)current_char]++;    
        }
        
        auto it = result.find(char_record);
        if (it == result.end()) {
            vector<string> new_anagram;
            new_anagram.push_back(current_string);
            result[char_record] = new_anagram;
        } else {
            result[char_record].push_back(current_string);
        }
    }
    return result;
}


int main() {
    vector<string> arr {"tea", "and", "ate", "eat", "den", "dan"};
    map<vector<int>, vector<string> > result
        = classify_anagrams (arr);
    auto it = result.begin();
    while (it != result.end()) {
        vector<string> temp = it->second;
        cout << "group: ";
        for (int i = 0; i < temp.size(); ++i) {
            cout << temp[i] << " ";
        }
        cout << endl;
        it++;
    }
}
