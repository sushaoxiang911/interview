#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

// didn't consider the situation that either p or q is not in the tree
node* lca(node* root, node* p, node* q) {
    if (root == NULL)
        return NULL;
    if (root == p && root == q)
        return root;
    node* x = lca(root -> left, p, q);
    // if return p or q means we find the two nodes
    // and we can try to find the common ancector
    // x is the ancestor
    if (x != NULL && x != p && x != q)
        return x;
    node* y = lca(root -> right, p, q);
    if (y != NULL && y != p && y != q)
        return y;
    
    
    // here we cannot distinguish p is child of q
    // or p is in tree q is not in tree
    if (root == p || root == q)
        return root;

    // x is p, y is q or x is q, y is p
    // p and q are separately in left and right
    if (x != NULL && y != NULL)
        return root;
    else if (x == NULL && y == NULL)
        return NULL;    
    else
        return x == NULL ? y : x;
}

// use a number to do that  
// 0 means none of p and q has the parent of current node
// 1 means there is p or q has the parent of current node
// 2 means there are both p and q have the parent of current node
int lca_3(node* root, node* p, node* q, node* &result) {
    if (root == NULL)
        return 0;
    
    int left = lca_3(root -> left, p, q, result);
    if (left == 2)
        return 2;
    int right = lca_3(root -> right, p, q, result);
    if (right == 2)
        return 2;
    if (root == p || root == q) {
        if (left == 1 || right == 1) {
            result = root;
            return 2;
        } else {
            return 1;
        }
    }
    
    if (left == 1 && right == 1) {
        result = root;
    }
    return left + right;
}

node* lca_3_fun(node* root, node* p, node* q) {
    node* result = NULL;
    int num = lca_3(root, p, q, result);
    if (num == 2)
        return result;
    else
        return NULL;
    
}


// use a bool to keep track if the node is the ancestor or not
// so we can distinguish
struct result_node {
    node* result;
    bool is_ancestor;
};

result_node lca_2(node* root, node* p, node* q) {
    if (root == NULL) {
        return result_node{NULL, false};
    }
    if (root == p && root == q)
        return result_node{root, true};

    result_node rl = lca_2(root -> left, p, q);
    if (rl.is_ancestor)
        return rl;

    result_node rr = lca_2(root -> right, p, q);
    if (rr.is_ancestor)
        return rr;
    
    if (root == p || root == q) {
        bool is_ancestor = rl.result != NULL || rr.result != NULL ? true : false;
        return result_node{root, is_ancestor};
    }
    if (rl.result != NULL && rr.result != NULL)
        return result_node{root, true};
    else if (rl.result == NULL && rr.result == NULL)
        return result_node{NULL, false};
    else 
        return result_node{rr.result != NULL ? rr.result : rl.result, false};
}
node* lca_2_fun(node* root, node* p, node* q) {
    result_node r = lca_2(root, p, q);
    if (r.is_ancestor)
        return r.result;
    else
        return NULL;
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
    node3 -> left = node4;
    node3 -> right = node5;
    node5 -> left = node6;
    
    node* node7 = new node;    

    node* result = lca_3_fun(node1, node4, node7);
    if (result == NULL)
        cout << "result: " << "NULL" << endl;
    else
        cout << "result: " << result -> val << endl;
}




