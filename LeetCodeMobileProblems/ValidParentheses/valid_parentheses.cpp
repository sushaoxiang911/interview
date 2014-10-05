#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


bool is_valid(string str) {
    if (str == "")
        return true;
    stack<char> s;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] =='[' || str[i] == '{')
            s.push(str[i]);
        else if (str[i] == ')') {
            if (s.top() == '(')
                s.pop();
            else
                return false;
        } else if (str[i] == ']') {
            if (s.top() == '[')
                s.pop();
            else
                return false;
        } else if (str[i] == '}') {
            if (s.top() == '{')
                s.pop();
            else
                return false;
        } else
            return false;
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main() {
    cout << "result: " << is_valid("([)]") << endl;
}
