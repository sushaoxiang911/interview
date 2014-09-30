#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};


node* reverse(node* head, int m, int n) {
    if (head == NULL)
        return NULL;
    
    node* dummy_head = new node;
    node* dummy_tail = dummy_head;
    
    node* cursor = head;    

    for (int i = 1; i < m; ++i) {
        dummy_tail -> next = cursor;
        dummy_tail = dummy_tail -> next;
        cursor = cursor -> next;
    }

    node* reverse_tail = cursor;
    node* previous = NULL;
    for (int i = m; i <= n; ++i) {
        node* temp = cursor -> next;
        cursor -> next = previous;
        previous = cursor;
        cursor = temp;
    }
    
    dummy_tail -> next = previous;
    reverse_tail -> next = cursor;
    return dummy_head -> next;
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
    
    node* result = reverse(node1, 1, 5);
    node* temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;



}
