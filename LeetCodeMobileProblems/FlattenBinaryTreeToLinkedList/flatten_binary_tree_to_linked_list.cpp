#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* flatten_help (node* root) {
    if (root == NULL)
        return NULL;
    else if (root -> left == NULL && root -> right == NULL)
// return the last child of the left subtree
        return root;
    
    else {
        node* left = root -> left;
        node* right = root -> right;
        
        // cancel the left child
        root -> left = NULL;
        if (left != NULL) {
            root -> right = left;
// get the last child from stack
            node* tmp = flatten_help(left);
            tmp -> left = NULL;
// this place is automatically get the last place of the left side
            if (right == NULL)
                return tmp;
            else
// if we have a right, append the right
                tmp -> right = right;
        }
// return the last element of the right
        return flatten_help (right);
    }
}


void flatten_2 (node* root) {
    flatten_help(root);
}

void flatten (node* root) {
    if (root != NULL) {
        node* left = root -> left;
        node* right = root -> right;
        root -> left = NULL;
        if (root -> left != NULL) 
            flatten(left);
        if (root -> right != NULL)
            flatten(right);
        if (left != NULL) {
            root -> right = left;
            node* temp = left;
            while (temp -> right != NULL) {
                temp = temp -> right;
            }
            temp -> right = right;
        }
    }
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node5 -> val = 5;
    node6 -> val = 6;
    node1 -> left = node2;
    node1 -> right = node5;
    node2 -> left = node3;
    node2 -> right = node4;
    node5 -> right = node6;
    flatten_2 (node1);
    node* temp = node1;
    while (temp) {
        cout << temp -> val << " ";
        temp = temp -> right;
    }
    cout << endl;
}



