#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int str_to_int (string s) {
    bool neg = false;

    int start = 0;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }
    int result = 0;
    for (int i = start; i < s.size(); ++i) {
        result = result * 10 + (s[i] - '0');
    }
    if (neg)
        result = -result;
    return result;
}

int cal (int num1, int num2, string op) {
    if (op == "+")
        return num1 + num2;
    if (op == "-")
        return num1 - num2;
    if (op == "*")
        return num1 * num2;
    if (op == "/")
        return num1 / num2;
}

int evaluate (vector<string> tokens) {
    stack<int> s;
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/") {
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            int result = cal(num1, num2, tokens[i]);
            s.push(result);
        } else {
            int num = str_to_int (tokens[i]);
            s.push(num);
        }
    }
    
    return s.top();
}


int main() {
    vector<string> tokens{"5", "1", "2", "+", "4", "*", "+", "3", "-"};
    cout << "result: " << evaluate(tokens) << endl;
}
