#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
// O(n^2) time complexity
// use a map to track the words list
// word list can have duplicate

vector<int> find_substring(vector<string> list, string str) {
    vector<int> result;
    if (str.empty())
        return result;
    if (list.empty()) {
        for (int i = 0; i < str.size(); ++i)
            result.push_back(i);
        return result;
    }
    // the dictionary
    map<string, int> dict;
    for (int i = 0; i < list.size(); ++i) {
        ++dict[list[i]];
    }
    
    // word_size
    int word_size = list[0].size();
    int whole_size = word_size * list.size();    

    // use a dp to track if the current position can potentially be expanded
    vector<bool> dp(str.size(), true);
    
   
    int cursor = 0;
    while (cursor + whole_size <= str.size()) {
        map<string, int> current_track;
        for (int i = 0; i < list.size(); ++i)
            current_track[list[i]] = 0;
        if (dp[cursor]) {
            // expands from here
            for (int i = 0; i < list.size(); ++i) {
                string temp_str = str.substr(cursor + i * word_size, word_size);
                auto it = current_track.find(temp_str);
                if (it == current_track.end()) {
                    for (int j = 0; j <= i; ++j) {
                        dp[cursor + word_size * j] = false;
                    }
                    break;
                }
                if (it -> second >= dict[temp_str]) {
                    for (int j = 0; j <= i; ++j) {
                        string temp_temp_str = str.substr(cursor + j * word_size, word_size);
                        if (temp_temp_str == temp_str) {
                            dp[cursor + word_size * j] = false;
                            break; 
                        }
                        dp[cursor + word_size * j] = false;
                    }
                    break;
                }
            }
            result.push_back(cursor);
        }
        ++cursor;
    }
    cout << "dp: " << endl;
    for (int i = 0; i < dp.size(); ++i)
        cout << dp[i] << " ";
    cout << endl;
    return result;
}
*/

// just use a map to record
// and check every potential start position
vector<int> find_substring(vector<string> list, string str) {
    vector<int> result;
    if (str.empty())
        return result;
    if (list.empty()) {
        for (int i = 0; i < str.size(); ++i)
            result.push_back(i);
        return result;
    }
    // the dictionary
    map<string, int> dict;
    for (int i = 0; i < list.size(); ++i) {
        ++dict[list[i]];
    }
    int word_size = list[0].size();
    int whole_size = word_size * list.size();

    for (int i = 0; i < str.size() - whole_size; ++i) {
        map<string, int> current_track;
        for (int j = 0; j < list.size(); ++j) {
            current_track[list[j]] = 0;
        }
        bool is_result = true;
        for (int j = 0; j < list.size(); ++j) {
            string current_str = str.substr(i + word_size * j, word_size);
            auto it = dict.find(current_str);
            if (it == dict.end()) {
                is_result = false;
                break;
            }
            ++current_track[current_str];
            if (current_track[current_str] > dict[current_str]) {
                is_result = false;
                break;
            }
        }
        if (is_result)
            result.push_back(i);
    
    }

    return result;

}

int main() {
    string str = "barfoothefoobarman";
    vector<string> list {"foo", "bar"};
    vector<int> result = find_substring(list, str);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}

