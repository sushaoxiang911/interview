#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};


node* merge_list(node* head1, node* head2) {
    node* result;
    if (head1 == NULL && head2 == NULL)
        return NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node* list1_it = head1;
    node* list2_it = head2;
    if (head1 -> val < head2 -> val) {
        result = head1;
        list1_it = list1_it -> next;
    } else {
        result = head2;
        list2_it = list2_it -> next;
    }
    node* result_it = result;
    while (list1_it != NULL && list2_it != NULL) {
        if (list1_it -> val < list2_it -> val) {
            result_it -> next = list1_it;
            list1_it = list1_it -> next;
            result_it = result_it -> next;
        } else if (list1_it -> val > list2_it -> val) {
            result_it -> next = list2_it;
            list2_it = list2_it -> next;
            result_it = result_it -> next;
        } else {
            result_it -> next = list1_it;
            result_it = result_it -> next;
            list1_it = list1_it -> next;
            result_it -> next = list2_it;
            result_it = result_it -> next;
            list2_it = list2_it -> next;
        }
    }
    if (list1_it != NULL) {
        result_it -> next = list1_it;
    } 
    if (list2_it != NULL) {
        result_it -> next = list2_it;
    }
    return result;
}


int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;
    
    node1 -> val = 1;
    node2 -> val = 3;
    node3 -> val = 7;
    node4 -> val = 10;
    node5 -> val = 2;
    node6 -> val = 5;
    node7 -> val = 6;
    
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node5 -> next = node6;
    node6 -> next = node7;
    
    node* result = merge_list(node1, node5);
    node* it = result;
    while (it != NULL) {
        cout << it -> val << " ";
        it = it -> next;
    }
    cout << endl;
}
