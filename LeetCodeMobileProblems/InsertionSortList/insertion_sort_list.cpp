#include <iostream>


using namespace std;

struct node {
    int val;
    node* next;
};


void insertion_sort (node* &head) {
    if (head == NULL)
        return;    
    node* current_insert = head -> next;
    node* ordered_last = head;    
    ordered_last -> next = NULL;   

    while (current_insert != NULL) {
        if (ordered_last -> val <= current_insert -> val) {
            node* change = current_insert;
            current_insert = current_insert -> next;
            ordered_last -> next = change;
            ordered_last = change;
            ordered_last -> next = NULL;
            continue;
        }
        node* insert_pos = head;
        node* insert_pos_prev = NULL;
        while (insert_pos != NULL) {
            if (insert_pos -> val > current_insert -> val) {
                node* change = current_insert;
                current_insert = current_insert -> next;
                change -> next = insert_pos;
                if (insert_pos_prev != NULL) {
                    insert_pos_prev -> next = change;
                } else {
                    head = change;
                }
                break;
            } 
            insert_pos_prev = insert_pos;
            insert_pos = insert_pos -> next;
        }
    }
}

int main () {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node1 -> val = 2;
    node2 -> val = 1;
    node3 -> val = 5;
    node4 -> val = 4;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node* head = node1;
    insertion_sort (head);  

    while (head != NULL) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}


