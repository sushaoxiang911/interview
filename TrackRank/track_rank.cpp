#include <iostream>

using namespace std;


// When there is a flow of data
// that means we need link list instead of arr
// to boost insertion

// two data structures that are related to comparison
// are heap and bst

// In this problem, we want to check every single int
// that is we need to search
// bst

// and everytime we add number, we have to traverse the tree
// we can add rank at that time

// every time we add a number
// we can know that if we find the right place for it
// that means before insertion, it is a NULL
// then if the new node is added as the right tree, then the rank is parent node rank + 1

// and when we add a small number
// every time we turn to the left subtree, we know that the parent rank should be plus by one
// and all the num that is bigger than the parent (all the nodes of right subtree)
// should be increased by one
// when we find the right place for this node, we can calculate the rank by parent rank - 1
struct node {
    int val;
    int rank;
    node* left;
    node* right;
};

void add_one(node* root) {
    if (root == NULL)
        return;
    root -> rank = root -> rank + 1;
    add_one(root -> left);
    add_one(root -> right);
}

void track_help(int num, node* &root, int rank) {
    if (root == NULL) {
        root = new node {num, rank, NULL, NULL};
        return;
    }
    if (root -> val < num) {
        if (root -> right == NULL) 
            track_help(num, root -> right, rank + root -> rank + 1);
        else
            track_help(num, root -> right, rank);
    } else {
        root -> rank = root -> rank + 1;
        if (root -> left == NULL) 
            track_help(num, root -> left, root -> rank - 1);
        else
            track_help(num, root -> left, rank);
        add_one(root -> right);
    }
}
void track(int num, node* &root) {
    track_help(num, root, 0);
}

int get_rank(int num, node* root) {
    if (root == NULL)
        return -1;
    if (root -> val == num)
        return root -> rank;
    if (num > root -> val)
        return get_rank(num, root -> right);
    else
        return get_rank(num, root -> left);
}


int main() {
    node* root = NULL;
    track(1, root);
    track(4, root);
    track(5, root);
    track(2, root);
    track(3, root);

    cout << "result: " << endl;
    cout << "1: " << get_rank(1, root) << endl;
    cout << "2: " << get_rank(2, root) << endl;
    cout << "3: " << get_rank(3, root) << endl;
    cout << "4: " << get_rank(4, root) << endl;
    cout << "5: " << get_rank(5, root) << endl;

}



