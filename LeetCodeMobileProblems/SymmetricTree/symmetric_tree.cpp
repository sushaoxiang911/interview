#include <iostream>


using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};
bool symmetric_tree_help(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;
    return (root1 -> val == root2 -> val) &&
            symmetric_tree_help(root1 -> left, root2 -> right) &&
            symmetric_tree_help(root1 -> right, root2 -> left);
}

bool symmetric_tree(node* root) {
    return symmetric_tree_help(root -> left, root -> right);
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
    node2 -> val = 2;
    node3 -> val = 2;
    node4 -> val = 3;
    node5 -> val = 4;
    node6 -> val = 4;
    node7 -> val = 3;
    
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node3 -> left = node6;
    node3 ->sright = node7;
    
    cout << "result: " << symmetric_tree(node1) << endl;

}
