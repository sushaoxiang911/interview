#include <iostream>
#include <stack>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

void recursion (node* root) {
    if (root == NULL)
        return;
    recursion (root -> left);
    recursion (root -> right);
    cout << root -> val << endl;
}

void iteration (node* root) {
    if (root == NULL)
        return;
    stack<node*> print;
    stack<node*> path;
    path.push(root);
    while (!path.empty()) {
        node* p = path.top();
        path.pop();
        if (p -> left != NULL)
            path.push(p -> left);
        if (p -> right != NULL)
            path.push(p -> right);
        print.push(p);
    }
    
    while (!print.empty()) {
        node *p = print.top();
        print.pop();
        cout << p -> val << endl;
    }
}

void iteration_2 (node* root) {
    if (root == NULL)
        return;
    stack<node*> path;
    node* p = root;
    // to record the last one
    node* q = root;
    while (p != NULL) {
        // notice that for the most left node, this time we don't put it into the stack
        while (p != NULL) {
            path.push(p);
            p = p -> left;
        }
        
        p = path.top();
        path.pop();
        

        // when should we visit the node
        // one condition is there is no right child, then we can visit the node
        // another condition is the last node visited is the right child fo the current one
        // must use while loop here, or for the next out round, first while loop will be used
        // the same concept, we have to go upward until we branch to the right node 
        // and start over
        while (p != NULL && (p -> right == NULL || p -> right == q)) {
            cout << p -> val << endl;
            // record the last
            q = p;
            if (path.empty()) 
                return;
            p = path.top();
            path.pop();
        }
        // means this node has right child and we have to push it back to the stack
        path.push(p);
        // start over with the node's right child
        p = p -> right;
    }
}

void iteration_3 (node* root) {
    if (root == NULL)
        return;
    stack<node*> path;
    node* p = root;
    node* q = NULL;
    
    while (1) {
        if (p != NULL) {
            path.push(p);   
            p = p -> left;
        } else {
            if (!path.empty()) {
                p = path.top();
                if (p -> right == NULL || p -> right == q) {
                    path.pop();
                    cout << p -> val << endl;
                    q = p;
                    p = NULL;
                } else {
                    p = p -> right;
                }
            } else {
                break;
            }
        }
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
    cout << "iteration 2: " << endl;
    iteration_2(node1);
    cout << endl;
    cout << "iteration 3: " << endl;
    iteration_3(node1);
    cout << endl;
}
