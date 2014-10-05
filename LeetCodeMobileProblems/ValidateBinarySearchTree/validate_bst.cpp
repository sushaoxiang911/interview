#include <iostream>
#include <climits>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

bool is_bst_help(int min, int max, node* root) {
    if (root == NULL)
        return true;
    if (root -> val > max)
        return false;
    if (root -> val < min)
        return false;
    return is_bst_help(min, root -> val, root -> left) &&
            is_bst_help(root -> val, max, root -> right);
}

bool is_bst(node* root) {
    return is_bst_help(INT_MIN, INT_MAX, root);
}

// inorder traversal
// every time we record the traversed node
// that is biggest number of all the nodes we have traversed
bool is_bst_2_help(int last_node, node* root) {
    if (root == NULL)
        return true;
    if (!is_bst_2_help(last_node, root -> left))
        return false;
    if (root -> val < last_node)
        return false;
    last_node = root -> val;
    if (!is_bst_2_help(last_node, root -> right))
        return false;
    return true;
}
bool is_bst_2(node* root) {
    return is_bst_2_help(INT_MIN, root);
}  

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    
    node1 -> val = 5;
    node2 -> val = 2;
    node3 -> val = 6;
    node4 -> val = 3;
    node5 -> val = 7;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> right = node4;
    node3 -> right = node5;
    cout << "result: " << is_bst_2(node1) << endl;
}
