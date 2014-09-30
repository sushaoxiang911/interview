#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};


void traversal(node* root) {
    if (root == NULL)
        return;
    queue<node*> path;
    stack<node*> print;
    path.push(NULL);
    path.push(root);
    while (!path.empty()) {
        node* p = path.front();
        path.pop();
        print.push(p);
        if (p != NULL) {
            if (p -> right != NULL)
                path.push(p -> right);
            if (p -> left != NULL)
                path.push(p -> left);
        } else {
            if (!path.empty())
                path.push(NULL);
        }
    }
    print.pop();    
    while (!print.empty()) {
        node* p = print.top();
        print.pop();
        if (p != NULL)
            cout << p -> val << " ";
        else
            cout << endl;
    }
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
    node4 -> val = 15;
    node5 -> val = 7;

    node1 -> left = node2;
    node1 -> right = node3;
    node3 -> left = node4;
    node3 -> right = node5;

    traversal(node1);
}

