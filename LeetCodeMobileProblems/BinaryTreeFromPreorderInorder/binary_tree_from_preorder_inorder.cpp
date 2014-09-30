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
node* construct (vector<int> preorder, vector<int> inorder) {
    if (preorder.size() == 0)
        return NULL;
    node* root = new node;
    root -> val = preorder[0];
    int root_pos_inorder;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == root -> val) {
            root_pos_inorder = i;
            break;
        }
    }
    vector<int> left_preorder;
    vector<int> right_preorder;
    vector<int> left_inorder;
    vector<int> right_inorder;
    for (int i = 0; i < root_pos_inorder; ++i) {
        left_inorder.push_back(inorder[i]);
    }
    for (int i = root_pos_inorder + 1; i < inorder.size(); ++i) {
        right_inorder.push_back(inorder[i]);
    }

    for (int i = 1; i < left_inorder.size() + 1; ++i) {
        left_preorder.push_back(preorder[i]);
    }
    for (int i = left_inorder.size() + 1; i < preorder.size(); ++i) {
        right_preorder.push_back(preorder[i]);
    }
    root -> left = construct (left_preorder, left_inorder);
    root -> right = construct (right_preorder, right_inorder);

    return root;
}

void preorder_print (node* root) {
    if (root == NULL)
        return;
    cout << root -> val << endl;
    preorder_print (root -> left);
    preorder_print (root -> right);
}

void inorder_print (node* root) {
    if (root == NULL)
        return;
    inorder_print (root -> left);
    cout << root -> val << endl;
    inorder_print (root -> right);

}

int main() {
    vector<int> preorder {1, 2, 4, 5, 3, 6};
    vector<int> inorder {4, 2, 5, 1, 3, 6};
    node* root = construct (preorder, inorder);
    cout << "postorder:" << endl;
    preorder_print(root);
    cout << endl;
    cout << "inorder:" << endl;
    inorder_print(root);
    cout << endl;

}




