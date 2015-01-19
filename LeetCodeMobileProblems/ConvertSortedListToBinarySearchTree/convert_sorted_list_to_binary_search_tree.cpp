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
// this takes nlogn time complexity since every time we have to go through all the nodes to find mid
// and then construct it 
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

// this takes n, with the help of list_node pointer reference, 
// we go next of current every time so we do a depth first construction
// and we just go through all the nodes once. 
tree_node* sorted_list_to_binary_tree (list_node* head) {
}


tree_node* sorted_list_to_binary_tree_help(list_node* &current, int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    
    tree_node* left = sorted_list_to_binary_tree(current, start, mid - 1);

    tree_node* root = new tree_node;
    root -> val = current -> val;
    current = current -> next;

    tree_node* right = sorted_list_to_binary_tree(current, mid + 1, end);

    root -> left = left;
    root -> right = right;

    return root;
}

