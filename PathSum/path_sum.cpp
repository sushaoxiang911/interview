#include <iostream>
#include <vector>

using namespace std;

// find all the root->leaf path
// and we go from the last above
// so that we can find all the potential
// when we go backward the stack
// we can mark every one as the end point

struct node {
    int val;
    node* left;
    node* right;
};

void find_path(node* root, vector<int> path, int sum) {
    if (root == NULL)
        return;
    
    path.push_back(root -> val);
    int t = 0;
    for (int i = path.size() - 1; i >= 0; --i) {
        t += path[i];
        if (t == sum) { 
            for (int j = i; j < path.size(); ++j)
                cout << path[j] << " ";
            cout << endl;
        }
    }    
    find_path(root -> left, path, sum);
    find_path(root -> right, path, sum);
}

void find_path_fun(node* root, int sum) {
    vector<int> path;
    find_path(root, path, sum);
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node1 -> left = node2;
    node1 -> right = node3;
    node3 -> left = node4;
    
    node1 -> val = 1;
    node2 -> val = -1;
    node3 -> val = -1;
    node4 -> val = 0;
    
    find_path_fun(node1, 0);
}
