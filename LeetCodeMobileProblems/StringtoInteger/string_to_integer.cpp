#include <iostream>
#include <climits>

using namespace std;


int atoi(const char* str) {
    // check NULL
    if (str == NULL)
        return 0;
    int cursor = 0;
    while (str[cursor] == ' ')
        ++cursor;

    if (str[cursor] == '\0')
        return 0;
    
    // consider the out of bound
    long long ans = 0;
    int neg = 1;
    if (str[cursor] == '+' || str[cursor] == '-') {
        if (str[cursor] == '-')
            neg = -1;
        ++cursor;
    }
    
    while (str[cursor] <= '9' && str[cursor] >= '0') {
        ans = ans * 10 + (str[cursor] - '0');
        if (ans * neg > INT_MAX) 
            return INT_MAX;
        if (ans * neg < INT_MIN)
            return INT_MIN;
        ++cursor;
    }
    return ans * neg;

}

int main() {
    char str[] = "-1234";
    cout << "result: " << atoi(str) << endl;

}
