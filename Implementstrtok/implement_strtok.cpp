#include <iostream>
using namespace std;

// since everytime we call the strtok(NULL, "dsf") 
// we have to get next token
// that gives the hint of a static variable 
char* strtok (char* str, char* delimiter) {
    static char* current;
    // means we have a new call on delimit token
    if (str != NULL)
        current = str;
    // if cursor is null
    // means we have arrived the end of the string
    if (current == NULL)
        return NULL;
    
    char* start = NULL;
    char* cursor = current;

    while (*cursor != '\0') {
        char* temp;
        bool is_del = false;
        for (temp = delimiter; *temp != '\0'; temp++) {
            if (*cursor == *temp) {
                is_del = true;
                cursor++;
                break;
            } 
        }
        if (!is_del) {
            start = cursor;
            break;
        }
    }
    // how to find the last token
    // if we can not find a valid start point
    // it is the last token
    // return NULL
    if (start == NULL) {
        return NULL;
    }
    while (*cursor != '\0') {
        char* temp;
        for (temp = delimiter; *temp != '\0'; temp++) {
            if (*cursor == *temp) {
                *cursor = '\0';
                break;
            }
        }
        if (*cursor == '\0') {
            current = cursor + 1;
            break;
        }
        cursor++;
        current = cursor;
    }
    return start;
}

int main() {
    char str[] = "- This, a sample string";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL) {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
}



