#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};


node* merge(node* node1, node* node2) {
    node* dummy = new node;
    node* tail = dummy;
    while (node1 != NULL && node2 != NULL) {
        if (node1 -> val < node2 -> val) {
            tail -> next = node1;
            node1 = node1 -> next;
        } else {
            tail -> next = node2;
            node2 = node2 -> next;    
        }
        tail = tail -> next;
    }
    while (node1 != NULL) {
        tail -> next = node1;
        node1 = node1 -> next;
        tail = tail -> next;
    }
    while (node2 != NULL) {
        tail -> next = node2;
        node2 = node2 -> next;
        tail = tail -> next;    
    }
    node* head = dummy -> next;
    delete dummy;
    return head;
}

node* merge_sort_help(node* head) {
    if (head -> next == NULL) 
        return head;
    
    node* cursor1 = head;
    node* cursor2 = head;
    node* previous = NULL;
    while (cursor2 != NULL) {
        cursor2 = cursor2 -> next;
        if (cursor2 != NULL)
            cursor2 = cursor2 -> next;
        previous = cursor1;
        cursor1 = cursor1 -> next;        
    }
    
    previous -> next = NULL;
    node* left_head = head;
    node* right_head = cursor1;
    
    left_head = merge_sort_help(left_head);
    right_head = merge_sort_help(right_head);
    return merge(left_head, right_head);
}

node* merge_sort(node* head) {
    if (head == NULL || head -> next == NULL)
        return head;
    return merge_sort_help(head);
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node; 
    node* node5 = new node;
    
    node1 -> val = 3;
    node2 -> val = 2;
    node3 -> val = 5;
    node4 -> val = 6;
    node5 -> val = 1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    
    node* result = merge_sort(node1);
    node* temp = result;
    
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }    
    cout << endl;

}



