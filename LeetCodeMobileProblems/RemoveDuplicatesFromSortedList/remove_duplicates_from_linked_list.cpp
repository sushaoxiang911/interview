#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};


node* remove_duplicates_i(node* head) {
    if (head == NULL)
        return NULL;
    
    node *dummy_head = new node;
    node *dummy_tail = dummy_head;
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL) {
        if (prev == NULL || curr -> val != prev -> val) {
            dummy_tail -> next = curr;
            dummy_tail = dummy_tail -> next;
        }
        prev = curr;
        curr = curr -> next;
    }
    dummy_tail -> next = NULL;
    return dummy_head -> next;
}

node* remove_duplicates_ii(node* head) {
    if (head == NULL)
        return NULL;
    
    node* dummy_head = new node;
    node* dummy_tail = dummy_head;
    node* dummy_prev = NULL;

    node* prev = NULL;
    node* curr = head;

    while (curr != NULL) {
        if (prev == NULL || curr -> val != prev -> val) {
            dummy_tail -> next = curr;
            dummy_prev = dummy_tail;
            dummy_tail = dummy_tail -> next;
        } else {
            if (curr -> val == dummy_tail -> val) {
                dummy_tail = dummy_prev;
            }
        }
        prev = curr;
        curr = curr -> next;
    }
    dummy_tail -> next = NULL;
    return dummy_head -> next;


}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node1 -> val = 1;
    node2 -> val = 1;
    node3 -> val = 1;
    node4 -> val = 1;
    node5 -> val = 1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
   
    cout << "result 1: " << endl; 
    node *result = remove_duplicates_ii(node1);
    node *temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
