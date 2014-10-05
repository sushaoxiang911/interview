#include <iostream>
#include <vector>

using namespace std;

// notice we just need to track if it is a valid number or not

// use a dfs to do that
// set up state
int input(char c) {
    if (c == ' ')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c >= '0' && c <= '9')
        return 2;
    else if (c == '.')
        return 3;
    else if (c == 'e')
        return 4;
    else
        return -1;
}


bool is_number(const char* str) {
    if (str == NULL)
        return false;
    vector<vector<int> > transTable(9, vector<int> (5, -1));
    transTable[0][0] = 0;
    transTable[0][1] = 1;  
    transTable[0][2] = 2;  
    transTable[0][3] = 7;
    // .123 is valid
    transTable[7][2] = 3;
    transTable[1][2] = 2;
    // -.134 is valid  
    transTable[1][3] = 7;    
    transTable[2][0] = 6;  
    transTable[2][2] = 2;
    transTable[2][3] = 3;  
    transTable[2][4] = 4;
    transTable[3][0] = 6; 
    transTable[3][2] = 3;  
    transTable[3][4] = 4;  
    // 123e-123 is valid
    transTable[4][1] = 8;  
    transTable[8][2] = 5;  
    transTable[4][2] = 5;  
    transTable[5][2] = 5;  
    transTable[5][0] = 6;  
    transTable[6][0] = 6;      

    int current_state = 0;
    while (*str != '\0') {
        int current_input = input(*str);
        if (current_input == 5)
            return false;
        current_state = transTable[current_state][current_input];
        if (current_state == -1)
            return false;
        ++str; 
    }
    if (current_state == 2 || current_state == 3 || current_state == 5 || current_state == 6)
        return true;
    return false;
}

int main() {
    cout << is_number("  -12.12e-12  ") << endl;

}
