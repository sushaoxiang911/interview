#include <iostream>
#include <stack>

using namespace std;

stack<int> sort_stack(stack<int> s) {
    stack<int> r;
    while (!s.empty()) {
        int sort_num = s.top();
        s.pop();
        while (!r.empty() && r.top() > sort_num) {
            int move_num = r.top();
            r.pop();
            s.push(move_num);
        }
        r.push(sort_num);
    }
    return r;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(4);
    s.push(2);
    stack<int> r = sort_stack(s);
    cout << "result: " << endl;
    while (!r.empty()) {
        int num = r.top();
        r.pop();
        cout << num << " ";
    }
    cout << endl;
}
