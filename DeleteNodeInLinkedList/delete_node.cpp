#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

// swap value
void delete_node(node* pos) {
    if (pos == NULL)
        return;
    
    node* next_node = pos -> next;
    pos -> val = next_node -> val;
    pos -> next = next_node -> next;
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
    
    delete_node(node2);
    node* temp = node1;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
