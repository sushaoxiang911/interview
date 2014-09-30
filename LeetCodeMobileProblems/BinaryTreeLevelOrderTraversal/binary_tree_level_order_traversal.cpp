#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;
};
// use a NULL as a separator to divide different levels.
// or we can use a temp queue to do that every time use a new queue.
// then two while loops
void traversal (node* root) {
    if (root == NULL)
        return;
    queue<node*> path;
    path.push(root);
    path.push(NULL);
    while (!path.empty()) {
        node* p = path.front();
        path.pop();
        if (p != NULL) {
            cout << p -> val << " ";
            if (p -> left != NULL)
                path.push(p -> left);
            if (p -> right != NULL)
                path.push(p -> right);
        } else {
            cout << endl;
            if (!path.empty())
                path.push(NULL);
        }
    }
}


void traversal_2 (node* root) {
    if (root == NULL)
        return;
    queue<node*> q1;
    q1.push(root);
    while (!q1.empty()) {
        queue<node*> q2;
        while (!q1.empty()) {
            node* temp = q1.front();
            q1.pop();
            cout << temp -> val << " ";
            if (temp -> left != NULL)
                q2.push(temp -> left);
            if (temp -> right != NULL)
                q2.push(temp -> right);
        }
        q1 = q2;
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

    traversal_2(node1);
}
