#include <iostream>
#include <stack>

using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    int size() {
        return s1.size() + s2.size();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
    
    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int num = s1.top();
                s1.pop();
                s2.push(num);
            }
        }
        s2.pop();
    }
    void push(int num) {
        s1.push(num);
    }   
 
    int front() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int num = s1.top();
                s1.pop();
                s2.push(num);
            }
        }
        return s2.top();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "result: " << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}
