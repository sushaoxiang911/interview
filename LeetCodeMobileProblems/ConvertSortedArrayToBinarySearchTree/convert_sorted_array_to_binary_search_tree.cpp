#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* construct (vector<int> arr) {
    if (arr.empty())
        return NULL;
    node* root = new node;
    int value_index = (arr.size() - 1) / 2;
    int value = arr[value_index];
    root -> val = value;
    
    vector<int> left_arr;
    for (int i = 0; i < value_index; ++i) {
        left_arr.push_back(arr[i]);
    }
    vector<int> right_arr;
    for (int i = value_index + 1; i < arr.size(); ++i) {
        right_arr.push_back(arr[i]);
    }
    root -> left = construct(left_arr);
    root -> right = construct(right_arr);

    return root;
}

void inorder_print (node* root) {
    if (root == NULL)
        return;
    inorder_print (root -> left);
    cout << root -> val << endl;
    inorder_print (root -> right);

}

int main () {
    vector<int> arr {1, 2, 3, 4, 5, 6, 7};
    node* root = construct (arr);
    cout << "inorder: " << endl;
    inorder_print (root);
}
