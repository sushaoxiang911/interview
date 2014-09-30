#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};



// first consideration is inorder traversal, an recover the sorting
// if    5
//      / \
//     4   8
//    /   / \
//   2   6   10

// if we swap 4 and 5
// we have 2 5 4 6 8 10
// if we swap 4 6
// we have 2 6 5 4 8 10

// so we can find that
// two mismatching nodes are 
// the first node that is bigger than the next one
// and the last node that is smaller than the previous one

// so when do the inorder traversal, we only need to record the previous one node


void recover_help(node* root, node* &mismatch1, node* &mismatch2, node* &previous) {
    if (root == NULL)
        return;

    // left traverse until the left most one
    recover_help(root -> left, mismatch1, mismatch2, previous);
    // when we pop from the stack, we check previous and update the previous
    if (previous != NULL && root -> val < previous -> val) {
        if (mismatch1 == NULL) {
            mismatch1 = previous;
            mismatch2 = root;
        } else 
            mismatch2 = root;
    }
    previous = root;
    recover_help(root -> right, mismatch1, mismatch2, previous);
}

void recover(node* root) {
    node* mismatch1 = NULL;
    node* mismatch2 = NULL;
    node* previous = NULL;
    recover_help(root, mismatch1, mismatch2, previous);
    if (mismatch1 != NULL) {
        int temp = mismatch1 -> val;
        mismatch1 -> val = mismatch2 -> val;
        mismatch2 -> val = temp;
    }
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root -> left);
    cout << root -> val << " ";
    inorder(root -> right);
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node1 -> val = 5;
    node2 -> val = 4;
    node3 -> val = 8;
    node4 -> val = 2;
    node5 -> val = 6; 
    node6 -> val = 10;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node3 -> left = node5;
    node3 -> right = node6;
    
    node1 -> val = 10;
    node6 -> val = 5;
    inorder(node1);
    cout << endl;
    recover(node1);
    inorder(node1);
    cout << endl;
    
    

}


