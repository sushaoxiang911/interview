#include <iostream>

using namespace std;

// first find the mid of the list and cut it
// second reverse the second list
// combine two lists

struct node {
    int val;
    node* next;
};

node* cut(node* head) {
    if (head == NULL)
        return NULL;
    node* ptr1 = head;
    node* prev = NULL;
    node* ptr2 = head;
    
    while (ptr2 != NULL) {
        prev = ptr1;
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
        if (ptr2 != NULL)
            ptr2 = ptr2 -> next;
    }
    prev -> next = NULL;
    return ptr1;
}


node* reverse(node* head) {
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL) {
        node* temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* reorder(node* head) {
    if (head == NULL)
        return NULL;
    node* mid = cut(head);
    
    node* first_head = head;
    node* second_head = reverse(mid);
    
    node* dummy_head = new node;
    node* dummy_tail = dummy_head;
    
    while (first_head != NULL && second_head != NULL) {
        node* temp1 = first_head -> next;
        node* temp2 = second_head -> next;
        dummy_tail -> next = first_head;
        dummy_tail = dummy_tail -> next;
        dummy_tail -> next = second_head;
        dummy_tail = dummy_tail -> next;
        first_head = temp1;
        second_head = temp2;
    }
    if (first_head != NULL)
        dummy_tail -> next = first_head;
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
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node* result = reorder(node1);
    node* temp = result;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;



}
