#include <iostream>

using namespace std;


struct node {
    int val;
    node* left;
    node* right;
};

bool path_sum_help(node* root, int sum, int current_sum) {
    if (root == NULL) {
        return false;
    }
    if (root -> left == NULL && root -> right == NULL)
        return (current_sum + root -> val == sum);
    return (path_sum_help(root -> left, sum, current_sum + root -> val)
            || path_sum_help(root -> right, sum, current_sum + root -> val));
}

bool path_sum(node* root, int sum) {
    return path_sum_help(root, sum, 0);
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;
    node* node8 = new node;
    node* node9 = new node;
    node1 -> val = 5;
    node2 -> val = 4;
    node3 -> val = 8;
    node4 -> val = 11;
    node5 -> val = 13;
    node6 -> val = 4;
    node7 -> val = 7;
    node8 -> val = 2;
    node9 -> val = 1;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node3 -> left = node5;
    node3 -> right = node6;
    node4 -> left = node7;
    node4 -> right = node8;
    node6 -> right = node9;
    cout << "result: " << path_sum(node1, 22) << endl;
}
