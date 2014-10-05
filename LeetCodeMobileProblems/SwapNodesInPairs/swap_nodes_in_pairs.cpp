#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

node* swap_in_pair(node* head) {
    if (head == NULL || head -> next == NULL)
        return head;
    
    node* pair1 = head;
    node* pair2 = head -> next;
    node* next = pair2 -> next;
    pair2 -> next = pair1;
    pair1 -> next = swap_in_pair(next);
    return pair2;
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
    
    node* result = swap_in_pair(node1);
    node* temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
