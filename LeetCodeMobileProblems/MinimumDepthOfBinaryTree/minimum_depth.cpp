#include <iostream>
#include <climits>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

int get_min_depth(node* root) { 
    if (root -> left == NULL && root -> right == NULL)
        return 1;
    int left_depth = INT_MAX;
    if (root -> left)
        get_min_depth(root -> left);
    int right_depth = INT_MAX;
    if (root -> right)
        get_min_depth(root -> right);
    
    return left_depth < right_depth ? left_depth + 1 : right_depth + 1;
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
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node3 -> right = node6;
    cout << "result: " << get_min_depth(node1) << endl;

}
