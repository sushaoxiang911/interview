#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool is_valid_part(string s) {
    if (s[0] == '0')
        return s == "0";
    int num = stoi(s);
    return num > 0 && num <= 255;
}



// count is number of the 0-255
// index is the string s's index
void restore_help(vector<string> &result, string s, string current, int index, int count) {
    if (count == 4 && index == s.size()) {
        result.push_back(current.substr(0, current.size() - 1));
        return;
    }
    if (s.size() - index > ((4 - count) * 3))
        return;
    // every part should be at most 3 digit or it may be the last part so less than 3
    int valid_digit = 3;
    if (s.size() - index <= 3)
        valid_digit = s.size() - index;
    for (int i = 1; i <= valid_digit; ++i) {
        string current_part = s.substr(index, i);
        if (is_valid_part(current_part)) {
            string temp = current;
            temp += current_part;
            temp += '.';
            restore_help(result, s, temp, index + i, count + 1); 
        }
    }
    
}


vector<string> restore(string s) {
    vector<string> result;
    string current = "";
    restore_help(result, s, current, 0, 0);
    return result;
}

int main() {
    string s = "25525511135";
    vector<string> result = restore(s);
    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;
}



