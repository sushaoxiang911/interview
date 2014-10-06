#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

// two pointers
node* find_kth(node* head, int k) {
    if (head == NULL)
        return NULL;
    
    node* ptr1 = head;
    node* ptr2 = head;
    
    for (int i = 0; i < k - 1; ++i) {
        if (ptr1 == NULL)
            return NULL;
        ptr1 = ptr1 -> next;
    }
    
    while (ptr1 -> next != NULL) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return ptr2;
}

node* find_kth_help(node* head, int k, int &i) {
    if (head == NULL)
        return NULL;
    node* result = find_kth_help(head -> next, k, i);
    i = i + 1;
    if (i == k)
        return head;
    return result;
}
node* find_kth_2(node* head, int k) {
    int i = 0;
    return find_kth_help(head, k, i);
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
    
    node* result = find_kth_2(node1, 5);
    cout << "result: ";
    if (result != NULL)
        cout << result -> val << endl;
    else
        cout << "NULL" << endl;
}
