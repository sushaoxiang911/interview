#include <iostream>
#include <stack>

using namespace std;

struct node {
    int val;
    node* next;
};

// iterative
// find the middle place and use a stack

bool check_palindrome(node* head) {
    if (head == NULL)
        return true;
    // find the middle place
    node* cursor1 = head;
    node* cursor2 = head;
    
    stack<int> s;    

    // we use this to check if the list is even or odd
    while (cursor1 != NULL && cursor1 -> next != NULL) {
        s.push(cursor2 -> val);
        cursor2 = cursor2 -> next;
        cursor1 = cursor1 -> next;
        cursor1 = cursor1 -> next;
    }
    // if odd, we skip the middle one
    if (cursor1 != NULL)
        cursor2 = cursor2 -> next;
    while (cursor2 != NULL) {
        if (cursor2 -> val != s.top()) {
            return false;
        }
        s.pop();
        cursor2 = cursor2 -> next;
    }
    
    if (!s.empty())
        return false;
    return true;
}

// recursive
// we recursively check to the middle of the list, using int len to track the remain length
// and after we check the first one and the last one
// we return the last one's next and pop the recursion stack
// on the top level, we have the head inside the function and we return the node that 
// will compare with it.

node* check_palindrome_help(node* head, int len, bool &result) {
    if (head == NULL) {
        result = true;
        return NULL;
    }
    // we have the middle one
    if (len == 1) {
        result = true;
        return head -> next;
    }   
    // we have the middle two
    // aa b
    // we have to go back the stack
    if (len == 2) {
        result = (head -> val == head -> next -> val);
        return head -> next -> next;
    }
    
    node* left_node = check_palindrome_help(head -> next, len - 2, result);
    if (head -> val != left_node -> val)
        result = false;
    return left_node -> next;
}

bool check_palindrome_2(node* head) {
    int len = 0;
    node* temp = head;
    while (temp != NULL) {
        ++len;
        temp = temp -> next;
    }
    bool result = true;
    check_palindrome_help(head, len, result);
    return result;
}



int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 1;
    node5 -> val = 1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    
    cout << "result: " << check_palindrome_2(node1) << endl;
}
