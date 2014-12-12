#include <iostream>
#include <climits>

using namespace std;


struct node {
    int val;
    node* left;
    node* right;
};


// as checking if the tree is balance
// return a number that is the number of nodes that is a BST in the left and right
// say we cannot use bst to check if the new number can be a added to make a better BST
// so size and bst is just for answer
// max and min are the same as checking BST
// because for a node we may add it as a left tree or a right tree
// so max and min are both needed
int find_largest_BST_help(node* root, int &max, int &min, int &size, node* &bst) {
    if (root == NULL)
        return 0;
    bool is_BST = true;
    int left_BST_nodes = find_largest_BST_help(root -> left, max, min, size, bst);
    // have to use a current_min to record the min since it is the left tree
    // and later we will call right_tree where min will be replaced
    // since we don't know current node is the left child or the right child of the parent
    // we have to remember the min and max since we might use either of them
    // which we don't know
    int current_min = (left_BST_nodes == 0) ? root -> val : min;
    // left child is not a bst
    // or the current node is smaller than the max of left subtree 
    if (left_BST_nodes == -1 || 
            (root -> val <= max && left_BST_nodes != 0))
        is_BST = false;

    int right_BST_nodes = find_largest_BST_help(root -> right, max, min, size, bst);
    int current_max = (right_BST_nodes == 0) ? root -> val : max;

    if (right_BST_nodes == -1 ||
            (root -> val >= min && right_BST_nodes != 0))
        is_BST = false;
    
    if (is_BST) {
        max = current_max;
        min = current_min;
        int current_size = left_BST_nodes + right_BST_nodes + 1;
        if (current_size > size) {
            size = current_size;
            bst = root;
        }
    } else
        return -1;
}

node* find_largest_BST(node* root) {
    int max = INT_MAX;
    int min = INT_MIN;
    int size = 0;
    node* bst = NULL;
    find_largest_BST_help(root, max, min, size, bst);
    return bst;
}

int main () {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;

    node2 -> val = 4;
    node5 -> val = 8;
    node6 -> val = 6;
    node7 -> val = 9;
    node4 -> val = 5;
    node1 -> val = 12;
    node3 -> val = 10;
    
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node5 -> left = node6;
    node5 -> right = node7;

    node* root = find_largest_BST(node1);
    cout << "result: " << root -> val << endl;

}






