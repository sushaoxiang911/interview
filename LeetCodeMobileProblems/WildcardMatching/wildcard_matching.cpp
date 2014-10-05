#include <iostream>
#include <string>

using namespace std;


bool is_match(string str, string pat) {
    if (!str.empty() && pat.empty())
        return false;
    if (str.empty() && pat.empty())
        return true;
    
    if (pat[0] == str[0] || pat[0] == '?') {
        return is_match(str.substr(1), pat.substr(1));
    }
    
    if (pat[0] == '*') {
        for (int i = 0; i < str.size(); ++i) {
            if (is_match(str.substr(1), pat.substr(1)))
                return true;
        }
        return false;
    }
}

int main() {
    string str = "aa";
    string pat = "**";
    cout << "result: " << is_match(str, pat) << endl;
}
