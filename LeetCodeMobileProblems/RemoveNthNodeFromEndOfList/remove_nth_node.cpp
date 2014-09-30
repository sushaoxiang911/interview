#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

void remove_node(node* &head, int n) {
    if (head == NULL || n == 0)
        return;
    node* ptr1 = head;
    node* ptr2 = head;
    node* prev = NULL;
    for (int i = 1; i < n; ++i)
        ptr1 = ptr1 -> next;
    while (ptr1 -> next != NULL) {
        ptr1 = ptr1 -> next;
        prev = ptr2;
        ptr2 = ptr2 -> next;
    }
    if (ptr2 == head)
        head = ptr2 -> next;
    else {
        prev -> next = ptr2 -> next;
    }
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    
    node* head = node1;
    remove_node(head, 3);
    
    node* temp = head;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
