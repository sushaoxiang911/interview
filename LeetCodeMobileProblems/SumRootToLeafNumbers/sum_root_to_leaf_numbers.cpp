#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

void get_sum_help(node* root, int &sum, int number) {
    if (root == NULL)
        return;
    int current_number = number * 10 + root -> val;
    if (root -> left == NULL && root -> right == NULL) {
        sum += current_number;
        return;
    }
    if (root -> left != NULL) {
        get_sum_help(root -> left, sum, current_number);
    }
    if (root -> right != NULL) {
        get_sum_help(root -> right, sum, current_number);
    }
}


int get_sum(node* root) {
    int sum = 0;
    get_sum_help(root, sum, 0);
    return sum;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node1 -> val = 1;
    node2 -> val = 2;
    node3 -> val = 3;
    node4 -> val = 4;
    node1 -> left = node2;
    node1 -> right = node3;
    node3 -> left = node4;
    cout << "result: " << get_sum(node1) << endl;
}

