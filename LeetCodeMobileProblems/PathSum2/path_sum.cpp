#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};


void path_sum_help(vector<vector<int> > &result, node* root, int sum,
                        int current_sum, vector<int> path) {
    if (root == NULL)
        return;
    
    if (root -> left == NULL && root -> right == NULL) {
        if (current_sum + root -> val == sum) {
            path.push_back(root -> val);
            result.push_back(path);
            return;
        }
    }
    
    path.push_back(root -> val);
    path_sum_help(result, root -> left, sum, current_sum + root -> val, path);
    path_sum_help(result, root -> right, sum, current_sum + root -> val, path);

}

vector<vector<int> > path_sum(node* root, int sum) {
    vector<vector<int> > result;
    vector<int> path;
    path_sum_help(result, root, sum, 0, path);
    return result;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;
    node* node8 = new node;
    node* node9 = new node;
    node* node10 = new node;
    node1 -> val = 5;
    node2 -> val = 4;
    node3 -> val = 8;
    node4 -> val = 11;
    node5 -> val = 13;
    node6 -> val = 4;
    node7 -> val = 7;
    node8 -> val = 2;
    node9 -> val = 1;
    node10 -> val = 5;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node3 -> left = node5;
    node3 -> right = node6;
    node4 -> left = node7;
    node4 -> right = node8;
    node6 -> right = node9;
    node6 -> left = node10;
    vector<vector<int> > result = path_sum(node1, 22);

    cout << "result: " << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); ++j) 
            cout << result[i][j] << " ";    
        cout << endl;   
    }
}
