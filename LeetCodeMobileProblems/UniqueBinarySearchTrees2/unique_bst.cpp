#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

vector<node*> generate(int start, int end) {
    vector<node*> result;
    if (start < end) {
        result.push_back(NULL);
        return result;
    }
    for (int i = 0; i < n; ++i) {
        vector<node*> left_nodes = generate(start, i - 1);
        vector<node*> right_nodes = generate(i + 1, end);
        
        // here we can see that nodes are used multiple times
        // how to solve this?
        for (int j = 0; j < left_nodes.size(); ++j) {
            for (int k = 0; k < right_nodes.size(); ++k) {
                node* root = new node;
                root -> val = i;
                root -> left = left_nodes[j];
                root -> right = right_nodes[k];
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<node*> unique_trees(int n) {
    vector<node*> result = generate(1, n);
    return result;
}
