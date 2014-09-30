#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

// use dummy node to get rid of a condition check
// we do not need to check if the head of two lists exists or not
node* partition(node* head, int x) {
    node* left_dummy = new node;
    node* right_dummy = new node;
    
    node* left_head = left_dummy;
    node* left_tail = left_dummy;
    node* right_head = right_dummy;
    node* right_tail = right_dummy;
    
    node* current = head;
    while (current != NULL) {
        if (current -> val < x) {
            left_tail -> next = current;
            left_tail = current;
        } else {
            right_tail -> next = current;
            right_tail = current;
        }
        current = current -> next;
    }
    right_tail -> next = NULL;
    left_tail -> next = right_head -> next;
    node* result = left_head -> next;
    delete left_dummy;
    delete right_dummy;
    return result;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node1 -> val = 1;
    node2 -> val = 4;
    node3 -> val = 3;
    node4 -> val = 2;
    node5 -> val = 5;
    node6 -> val = 2;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5; 
    node5 -> next = node6;
    node* result = partition(node1, 3);
    cout << "result: " << endl;
    node* current = result;
    while (current != NULL) {
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}
