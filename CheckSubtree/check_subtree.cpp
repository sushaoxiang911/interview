#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// the first method is to check if the tree1 is the same with tree2 for every node
// that takes O(mn)

struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
};

bool check_same_tree (node* tree1, node* tree2) {
    if (tree1 == NULL && tree2 == NULL)
        return true;
    if (tree1 == NULL || tree2 == NULL)
        return false;

    if (tree1 -> val != tree2 -> val)
        return false;
    return check_same_tree(tree1 -> left, tree2 -> left) &&
                check_same_tree(tree1 -> right, tree2 -> right);
}


bool check_subtree_help(node* tree1, node* tree2) {
    if (tree2 == NULL)
        return false;
    bool result = check_same_tree(tree1, tree2);
    if (result)
        return true;
    else
        return check_subtree_help(tree1, tree2 -> left) || 
            check_subtree_help(tree1, tree2 -> right);
    
}

bool check_subtree(node* tree1, node* tree2) {
    if (tree1 == NULL)
        return true;
    return check_subtree_help(tree1, tree2);
}

// there is an O(m+n) algorithm
// that is find the preorder and inorder traversal of two trees
// if the smaller tree's preorder is the bigger one's preorder's subarray
// and the smaller tree's inorder is the bigger one's inorder's subarray
// then smaller is the subtree of the bigger one
//
// it is O(m+n) since checking subarray could take linear if using KMP
//
// notice that to make difference between 3 and 3, we have to include NULL as a traversal node
//                                       /       \
//                                      3         3


// we assume all the nodes have positive value
// and 0 denotes NULL
void preorder_null(node* tree, vector<int> &container) {
    if (tree == NULL) {
        container.push_back(0);
        return;
    }
    container.push_back(tree -> val);
    preorder_null(tree -> left, container);
    preorder_null(tree -> right, container);
} 

void inorder_null (node* tree, vector<int> &container) {
    if (tree == NULL) {
        container.push_back(0);
        return;
    }
    inorder_null(tree -> left, container);
    container.push_back(tree -> val);
    inorder_null(tree -> right, container);
}

bool check_subtree_2(node* tree1, node* tree2) {
    vector<int> tree1_preorder;
    preorder_null(tree1, tree1_preorder);
    vector<int> tree1_inorder;
    inorder_null(tree1, tree1_inorder);
    vector<int> tree2_preorder;
    preorder_null(tree2, tree2_preorder);
    vector<int> tree2_inorder;
    inorder_null(tree2, tree2_inorder);

    auto preorder_pos = search(tree2_preorder.begin(), tree2_preorder.end(), 
                                tree1_preorder.begin(), tree1_preorder.end());
    auto inorder_pos = search(tree2_inorder.begin(), tree2_inorder.end(),
                                tree1_inorder.begin(), tree1_inorder.end());
    return (preorder_pos != tree2_preorder.end() && inorder_pos != tree2_inorder.end());
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
    node3 -> val = 3;
    node4 -> val = 4;
    node5 -> val = 5;
    node6 -> val = 6;
    node7 -> val = 7;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node4 -> right = node6;
    node3 -> right = node7;


    node* node8 = new node;
    node* node9 = new node;
    node* node10 = new node;
    node* node11 = new node;

    node8 -> val = 2;
    node9 -> val = 4;
    node10 -> val = 5;
    node11 -> val = 1;
    
    node8 -> left = node9;
    node8 -> right = node10;
    node9 -> right = node11;

    cout << "result: " << check_subtree_2(node8, node1) << endl;    

}



