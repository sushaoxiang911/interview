#include <iostream>
#include <string>

using namespace std;

void reverse_help(string &s, int start, int end) {
    while (start <= end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        ++start;
        --end;
    }
}


void reverse_words(string &s) {
    if (s == "")
        return;
    reverse_help(s, 0, s.size() - 1);
    int start = 0;
    int end = 0;
    while (end < s.size()) {
        if (s[start] == ' ') {
            ++start;
            ++end;
        } else {
            if (s[end] == ' ') {
                reverse_help(s, start, end - 1);
                start = end;
            } else {
                end++;
            }
        }
    }
    if (start < s.size()) 
        reverse_help(s, start, s.size() - 1);
}

int main() {
    string s = "the sky is blue";
    reverse_words(s);
    cout << "result: " << s << endl;
}
