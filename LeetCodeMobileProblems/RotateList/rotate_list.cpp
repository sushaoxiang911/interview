#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

node* rotate(node* head, int k) {
    if (head == NULL || k == 0)
        return head;
    
    int length = 0;
    node* result;
    node* cursor = head;
    node* previous = NULL;
    while (cursor != NULL) {
        ++length;
        previous = cursor;
        cursor = cursor -> next;
    }
    
    int rotate_num = k % length;
    
    cursor = head;
    for (int i = 0; i < length - rotate_num - 1; ++i) {
        cursor = cursor -> next;
    }

    previous -> next = head;
    result = cursor -> next;
    cursor -> next = NULL;
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
    node4 -> val = 4;
    node5 -> val = 5;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    cout << "result: " << endl;

    node* result = rotate(node1, 7);
    node* temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

}
