#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node* next;
};


// notice that we cannot use bfs, since the queue will use O(logn) extra space
// we can use the next pointer to do the bfs


void populate(node* root) {
    
    node* head = root;
    while (head != NULL) {
        // from the current head to traversal
        node* cursor = head;
        node* dummy_head = new node;
        node* dummy_tail = dummy_head;
        dummy_head -> next = NULL;
        while (cursor != NULL) {
            if (cursor -> left != NULL) {
                dummy_tail -> next = cursor -> left;
                dummy_tail = dummy_tail -> next;
            }
            if (cursor -> right != NULL) {
                dummy_tail -> next = cursor -> right;
                dummy_tail = dummy_tail -> next;
            }
            cursor = cursor -> next;
        }
        head = dummy_head -> next;
        delete dummy_head;
    }
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node5 -> val = 5;
    node6 -> val = 6;

    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node3 -> right = node6;
    
    populate(node1);
    
    cout << "result: " << endl;
    node* head = node1;
    while (head != NULL) {
        cout << head -> val << " ";
        head = head -> next;
    } 
    cout << endl;
    head = node2;
    while (head != NULL) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
    head = node4;
    while (head != NULL) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
