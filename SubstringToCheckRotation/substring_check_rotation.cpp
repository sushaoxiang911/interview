#include <iostream>
#include <string>

using namespace std;

bool substring_check_rotation (string string1, string string2) {
    
    if (string1.length() != string2.length())
        return false;

    string temp = string1 + string1;
    
    size_t pos = temp.find(string2);
    
    if (pos == string::npos)
        return false;

    return true;

}

int main () {

    string string1 = "abcd";
    string string2 = "cdab";
    string string3 = "cbad";

    cout << "string1 vs string2: " << substring_check_rotation (string1, string2) << endl;
    cout << "string1 vs string3: " << substring_check_rotation (string1, string3) << endl;
    return 0;

}
