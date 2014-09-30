#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

bool is_same_tree(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if ((root1 == NULL && root2 != NULL) ||
            (root1 != NULL && root2 == NULL))
        return false;
    return root1 -> val == root2 -> val && 
            is_same_tree(root1 -> left, root2 -> left) && 
            is_same_tree(root1 -> right, root2 -> right);
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node1 -> left = node2;
    node4 -> left = node5;
    node4 -> right = node6;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 1;
    node5 -> val = 2;
    node6 -> val = 3;
    cout << "result: " << is_same_tree(node1, node4) << endl;
}
