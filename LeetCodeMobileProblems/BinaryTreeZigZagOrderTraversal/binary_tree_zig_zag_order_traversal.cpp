#include <iostream>
#include <vector>

using namespace std;

// use a simple vector to do that
// since we are going to use a temp container
// then vector provides random access
// when rotate the direction of accessing
// we always comes from the end back to begining of the current container
// we only need to consider we should push_back left child first or right child first
// that is where the rotation occurs

struct node {
    int val;
    node* left;
    node* right;
};

void traversal (node* root) {
    if (root == NULL) 
        return;
    vector<node*> current;
    bool order = true;
    current.push_back(root);
    while (!current.empty()) {
        for (int i = 0; i < current.size(); ++i)
            cout << current[i] -> val << " ";
        cout << endl;
        vector<node*> temp;
        // we always come from right to left when constructing the next level
        for (int i = current.size() - 1; i >= 0; --i) {
            // if order, then the current order is left to right
            // then next order is right to left and the right child should be first access
            node* current_node = current[i];
            if (order) {
                if (current_node -> right != NULL)
                    temp.push_back(current_node -> right);
                if (current_node -> left != NULL)
                    temp.push_back(current_node -> left);
            } else {
                if (current_node -> left != NULL)
                    temp.push_back(current_node -> left);
                if (current_node -> right != NULL)
                    temp.push_back(current_node -> right);
            }
        }
        order = !order;
        current = temp;
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
    node1 -> val = 3;
    node2 -> val = 9;
    node3 -> val = 20;
    node4 -> val = 10;
    node5 -> val = 15;
    node6 -> val = 7;
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node3 -> left = node5;
    node3 -> right = node6;

    traversal(node1);

}



