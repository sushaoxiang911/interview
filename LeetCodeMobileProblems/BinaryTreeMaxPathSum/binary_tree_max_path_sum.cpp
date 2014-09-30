#include <iostream>
#include <algorithm>

using namespace std;
// the max sum mignt not neccessarily contain the root node
// so every node can be the root of the max path
// the recursion idea is 
// for every node, left max path + node value + right max path is the max sum
// and the recursion is by the max sum
// notice that when go upward in stack, there might be three potential max sum
// the node itself, left max path + node value, right max path + node value
// depth first search
// for every binary tree, between two nodes there is only one path
// so when you go bottom up, you will only need to add the node value to the last time left side

struct node {
    int val;
    node* left; 
    node* right;
};

int max_sum_path_helper (node* p, int& max_sum) {
    if (p == NULL)
        return 0;
    int l_side = max_sum_path_helper (p -> left, max_sum);
    int r_side = max_sum_path_helper (p -> right, max_sum);
    int temp_sum = p -> val;
    // consider there might be a negative number here
    // and there is no need to go to the leaf node
    // if we don't add any side, that means we just choose the node
    if (l_side > 0)
        temp_sum += l_side;
    if (r_side > 0)
        temp_sum += r_side;
    if (temp_sum > max_sum)
        max_sum = temp_sum;

    return max(p -> val, p -> val + max(l_side, r_side));
}

int max_sum_path (node* root) {
    int max_sum = 0;
    max_sum_path_helper(root, max_sum);
    return max_sum;
}

int main () {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;

    node1 -> val = 3;
    node2 -> val = 9;
    node3 -> val = 20;
    node4 -> val = -1;
    node5 -> val = -1;

    node1 -> left = node2;
    node1 -> right = node3;
    node3 -> left = node4;
    node3 -> right = node5;

    cout << "result: " << max_sum_path(node1) << endl;
}
