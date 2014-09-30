#include <iostream>

using namespace std;

bool is_matching(const char *s, const char *p) {
    // if the pattern is eof, then s must be eof, since we cannot have more character to match
    // reverse is wrong
    // if the s is eof, then p might be a .* or c* which can match a eof
    if (*p == '\0')
        return *s == '\0';

    // we first check if the pattern's next character is '*'
    if (*(p + 1) != '*') {
        // if the next is not '*', we know the current two characters should be matching
        // the two matching means
        // *p == *s or *p is '.'  and *s is not ending
        return (((*p == *s) || (*p == '.' && *s != '\0')) && is_matching(s + 1, p + 1));
    } else {
        if (is_matching(s, p + 2))
            return true;
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (is_matching(s + 1, p + 2))
                return true;
            s++;
        }
        return false;
    }   
}


int main() {
    char* s = "aab";
    char* p = "c*a*b";
    cout << "result: " << is_matching(s, p) << endl;
}
