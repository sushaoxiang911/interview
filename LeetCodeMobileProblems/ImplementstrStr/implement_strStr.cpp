#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


// KMP
// http://blog.csdn.net/yaochunnian/article/details/7059486

// get_next
// http://www.docin.com/p-114495132.html
void get_next (char* pattern, int next[]) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (pattern[i] != '\0') {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}


char* strStr(char* haystack, char* needle) {
    if (haystack == NULL || needle == NULL)
        return NULL;
    if (needle[0] == '\0')
        return haystack;
    
    int i = 0;
    int j = 0;
    // the next array should be one larger than the length of the needle
    // because in the get_next function if it is abab then we may go to i++ j++ and next[i] = j
    int* next = new int[strlen(needle) + 1];
    
    get_next(needle, next);
    
    while (haystack[i] != '\0') {
        while (j >= 0 && haystack[i] != needle[j])
            j = next[j];
        ++i;
        ++j;
        if (needle[j] == '\0') {
            char* result = haystack + i - j;
            return result;
        }     
    }
    return NULL;
}

int main() {
    char* haystack = "abacababc";
    char* needle =   "abab";
    char* result = strStr(haystack, needle);
    cout << "result: " << result << endl;
}



