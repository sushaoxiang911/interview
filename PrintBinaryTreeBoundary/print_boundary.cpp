#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

// consider how the recursion works here
// for the left boundary
// left's left will be printed
// left's right will not be printed
// right's left will not be printed


// print the boundary as long as with the leaf node
// for the left one
// we print 2 6 7
// from top to bottom -- preorder
void print_left_bound(node* root, bool is_print) {
    if (root == NULL)
        return;
    if (is_print || (root -> left == NULL && root -> right == NULL))
        cout << root -> val << " ";

    // if we branch to left bound, we may want to print it if the node's parent is a boundary
    // if it is right, we must not print
    print_left_bound(root -> left, is_print);
    print_left_bound(root -> right, false);
}

// and for the right one
// we print 5 7
// from bottom to top -- postorder
void print_right_bound(node* root, bool is_print) {
    if (root == NULL)
        return;
    // similar
    print_right_bound(root -> left, false);
    print_right_bound(root -> right, is_print);
    if (is_print || (root -> left == NULL && root -> right == NULL))
        cout << root -> val << " ";
}


void print_boundary(node* root) {
    if (root == NULL)
        return;
    cout << root -> val << " ";
    print_left_bound(root -> left, true);
    print_right_bound(root -> right, true);
    cout << endl;
}


int main () {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;

    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node5 -> val = 5;
    node6 -> val = 6;
    node7 -> val = 7;
    
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node5 -> left = node6; 
    node5 -> right = node7;

    cout << "result: " << endl;
    print_boundary(node1);
}

