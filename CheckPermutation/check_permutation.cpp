#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// sort and traversal, O(nlogn)
bool check_1 (string string1, string string2) {
    
    if (string1.length() != string2.length()) 
        return false;
    sort (string1.begin(), string1.end());
    sort (string2.begin(), string2.end());

    for (int i = 0; i < string1.length(); i++) {
        if (string1[i] != string2[i]) 
            return false;
    }

    return true;

}

bool check_2 (string string1, string string2) {
    
    if (string1.length() != string2.length()) 
        return false;    

    int* letters1 = new int[256];
    int* letters2 = new int[256];
    // a map
    for (int i = 0; i < 256; i++) {
        letters1[i] = 0;
        letters2[i] = 0;
    }
    
    for (int i = 0; i < string1.length(); i++) {
        letters1[string1[i]] ++;
        letters2[string2[i]] ++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (letters1[i] != letters2[i])
            return false;
    }
    return true;
}


int main () {
    string string1 = "abcdefa";
    string string2 = "gfedcba";

    cout << "check_1: " << check_1(string1, string2) << endl;
    cout << "check_2: " << check_2(string1, string2) << endl;
           

    return 0;



}
