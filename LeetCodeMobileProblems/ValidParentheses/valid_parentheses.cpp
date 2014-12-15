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
        char current = str[i];
        if (current == '(' || current =='[' || current == '{')
            s.push(current);
        else {
            // before using top, always check the empty!
            if (s.empty())
                return false;
            char paired = s.top();
            if ((current == ')' && paired == '(') ||
                    (current == ']' && paired == '[') ||
                    (current == '}' && paired == '{'))
                s.pop();
            else
                return false;
        } 
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main() {
    cout << "result: " << is_valid("([)]") << endl;
}
