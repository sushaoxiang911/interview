#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

void reverse(node* begin, node* end) {
    node* previous = NULL;
    node* cursor = begin;
    while (previous != end) {
        node* temp = cursor -> next;
        cursor -> next = previous;
        previous = cursor;
        cursor = temp;
    }
}


node* reverse_nodes(node* head, int k) {
    if (head == NULL) 
        return NULL;
    
     
    node* dummy_head = new node;
    node* dummy_tail = dummy_head;
    
    node* cursor = head;
    while (cursor != NULL) {
        node* begin = cursor;
        node* end = NULL;
        bool not_enough = false;
        for (int i = 1; i < k; ++i) {
            cursor = cursor -> next;
            if (cursor == NULL) {
                not_enough = true;
                break;
            }
        }
        if (not_enough) {
            dummy_tail -> next = begin;
        } else {
            end = cursor;
            cursor = end -> next;
            reverse(begin, end);
            dummy_tail -> next = end;
            dummy_tail = begin;
        }
    }
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

    node* result = reverse_nodes(node1, 1);
    node* temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

}

