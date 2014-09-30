#include <iostream>
#include <stack>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

void recursion(node* root) {
    if (root == NULL)
        return;
    cout << root -> val << endl;
    recursion (root -> left);
    recursion (root -> right);
}

void iteration (node* root) {
    if (root == NULL)
        return;
    
    stack<node*> path;
    path.push(root);    

    while (!path.empty()) {
        node* p = path.top();
        path.pop();
        cout << p -> val << endl;
        if (p -> right)
            path.push(p -> right);
        if (p -> left)
            path.push(p -> left);
    }
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
    node3 -> right = node6;
    node3 -> left = node7;

    cout << "recursion: " << endl;
    recursion(node1);
    cout << endl;
    cout << "iteration: " << endl;
    iteration(node1);
    cout << endl;
}

