#include <iostream>

using namespace std;

struct list_node {
    int val;
    list_node* next;
};

struct tree_node {
    int val;
    tree_node* left;
    tree_node* right;
};

// find the mid value can be done by two pointer

tree_node* sorted_list_to_binary_search_tree (list_node* head) {
    if (head == NULL)
        return NULL;
    list_node* mid = head;
    // this is used to do the first half
    // list is modified
    // the original list is cut
    list_node* pre_mid = NULL;
    list_node* tail = head -> next;
    while (tail != NULL) {
        tail = tail -> next;
        if (tail)
            tail = tail -> next;
        pre_mid = mid;
        mid = mid -> next;
    }

    tree_node* root = new tree_node;
    root -> val = mid -> val;
    
    if (pre_mid == NULL)
        root -> left = NULL;
    else {
        pre_mid -> next = NULL;
        root -> left = sorted_list_to_binary_search_tree (head);
    }
    root -> right = sorted_list_to_binary_search_tree (mid -> next);
    return root;
        
}
