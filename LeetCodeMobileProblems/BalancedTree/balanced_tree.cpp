#include <iostream>

using namespace std;

struct node {
    int val;
    node* right;
    node* left;
};

// calculate the height of left subtree and right subtree and compare

int get_height (node* p) {
    if (!p) return 0;
    int left_height = get_height (p -> left);
    int right_height = get_height (p -> right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}


bool check_balanced_1 (node* root) {
    if (root == NULL)
        return true;
    int left_height = get_height (root -> left);
    int right_height = get_height (root -> right);
    int diff = left_height - right_height;
    if (diff < 0)
        diff = -diff;
    if (diff > 1)
        return false;
    else
        return check_balanced_1 (root -> left) && check_balanced_1 (root -> right); 
}


// check balanced and the height together
// consider to use -1 as the non balanced, use stack to bounce back -1
// else calculate the height 
int check_balanced_2(node* root) {
    if (root == NULL)
        return 0;
    int left_balance = check_balanced_2 (root -> left);
    int right_balance = check_balanced_2 (root -> right);
    if (left_balance == -1 || right_balance == -1)
        return -1;
    int diff = left_balance - right_balance;
    if (diff < 0)
        diff = -diff;
    if (diff > 1)
        return -1;
    else
        return (left_balance > right_balance) ? left_balance + 1 : right_balance + 1;
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
    node3 -> right = node6;
    node3 -> left = node7;

    cout << "result: " << check_balanced_2 (node1) << endl;
}






