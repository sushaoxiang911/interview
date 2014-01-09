#include <iostream>

using namespace std;

struct tree_node {
    int val;
    tree_node* left_child;
    tree_node* right_child;    

};


void preorder_traversal (tree_node* node) {
    if (node == NULL){
        return;
    }
    cout << node -> val << " ";
    preorder_traversal (node -> left_child);
    preorder_traversal (node -> right_child);
         
    
}


void inorder_traversal (tree_node* node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal (node -> left_child);
    cout << node -> val << " ";
    inorder_traversal (node -> right_child);
}

void postorder_traversal (tree_node* node) {
    if (node == NULL) {
        return;
    }
    postorder_traversal (node -> left_child);
    postorder_traversal (node -> right_child);
    cout << node -> val << " ";
}


int main () {
    tree_node* node1 = new tree_node;
    tree_node* node2 = new tree_node;
    tree_node* node3 = new tree_node;
    tree_node* node4 = new tree_node;
    tree_node* node5 = new tree_node;

    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node5 -> val = 5;

    node1 -> left_child = node2;
    node1 -> right_child = node3;
    node2 -> left_child = node4;
    node2 -> right_child = node5;
    
    cout << "preorder: " << endl;
    preorder_traversal (node1);
    cout << endl;

    cout << "inorder: " << endl;
    inorder_traversal (node1);
    cout << endl;

    cout << "postorder: " << endl;
    postorder_traversal (node1);
    cout << endl;

    return 0;
}

