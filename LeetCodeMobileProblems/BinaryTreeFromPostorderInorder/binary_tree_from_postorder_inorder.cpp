#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

// actuall we can use position int and a const reference of the vectors to do that
// to make it directly, we copy vectors
node* construct (vector<int> postorder, vector<int> inorder) {
    if (postorder.size() == 0)
        return NULL;
    node* root = new node;
    root -> val = postorder[postorder.size() - 1];
    int root_pos_inorder;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == root -> val) {
            root_pos_inorder = i;
            break;
        }
    }
    vector<int> left_postorder;
    vector<int> right_postorder;
    vector<int> left_inorder;
    vector<int> right_inorder;
    for (int i = 0; i < root_pos_inorder; ++i) {
        left_inorder.push_back(inorder[i]);
    }
    for (int i = root_pos_inorder + 1; i < inorder.size(); ++i) {
        right_inorder.push_back(inorder[i]);
    }

    for (int i = 0; i < left_inorder.size(); ++i) {
        left_postorder.push_back(postorder[i]);
    }
    for (int i = left_inorder.size(); i < postorder.size() - 1; ++i) {
        right_postorder.push_back(postorder[i]);
    }
    root -> left = construct (left_postorder, left_inorder);
    root -> right = construct (right_postorder, right_inorder);
    
    return root;
}

void postorder_print (node* root) {
    if (root == NULL)
        return;
    postorder_print (root -> left);
    postorder_print (root -> right);
    cout << root -> val << endl;
}

void inorder_print (node* root) {
    if (root == NULL)
        return;
    inorder_print (root -> left);
    cout << root -> val << endl;
    inorder_print (root -> right);

}

int main() {
    vector<int> postorder {4, 5, 2, 6, 3, 1};
    vector<int> inorder {4, 2, 5, 1, 3, 6};
    node* root = construct (postorder, inorder);
    cout << "postorder:" << endl;
    postorder_print(root);
    cout << endl;
    cout << "inorder:" << endl;
    inorder_print(root);
    cout << endl;
    
}











