#include <iostream>
#include <deque>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};
bool symmetric_tree_help(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;
    return (root1 -> val == root2 -> val) &&
            symmetric_tree_help(root1 -> left, root2 -> right) &&
            symmetric_tree_help(root1 -> right, root2 -> left);
}

bool symmetric_tree(node* root) {
    return symmetric_tree_help(root -> left, root -> right);
}

// iterative
bool symmetric_tree_2(node* root) {
    deque<node*> q;
    q.push_back(root);
    while (1) {
        bool is_ended = true;
        for (int i = 0; i < q.size(); ++i) {
            if (q[i] != NULL)
                is_ended = false;
        }
        if (is_ended)
            return true;
        // check is palindrome
        int start = 0;
        int end = q.size() - 1;
        while (start < end) {
            if ((q[start] == NULL && q[end] != NULL) ||
                    (q[start] != NULL && q[end] == NULL))
                return false;
            if (q[start] -> val != q[end] -> val)
                return false;
            start++;
            end--;
        }
        deque<node*> temp_q;
        while (!q.empty()) {
            node* temp = q.front();
            q.pop_front();
            if (temp != NULL) {
                temp_q.push_back(temp -> left);
                temp_q.push_back(temp -> right);
            }
        }
        q = temp_q;
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
    node3 -> val = 2;
    node4 -> val = 3;
    node5 -> val = 4;
    node6 -> val = 5;
    node7 -> val = 3;
    
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node3 -> left = node6;
    node3 -> right = node7;
    
    cout << "result: " << symmetric_tree(node1) << endl;
    cout << "result2: " << symmetric_tree_2(node1) << endl;
}
