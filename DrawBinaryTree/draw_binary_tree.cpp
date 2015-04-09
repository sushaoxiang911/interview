#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    int pos = 0;
    node* left = NULL;
    node* right = NULL;
};
// use one traversal to traverse all the node and shift node position
void shift_tree(node* root, int shift_pos) {
    if (root == NULL)
        return;
    root -> pos = root -> pos + shift_pos;
    shift_tree(root -> left, shift_pos);
    shift_tree(root -> right, shift_pos);
}
int calc_shift_pos(node* left_tree, node* right_tree) {
    int result = 0;
    while (left_tree != NULL && right_tree != NULL) {
        // here we want the right pos should be at least 2 further than the left pos
        int temp_result = (right_tree -> pos - left_tree -> pos) < 2 ? 
                            2 - (right_tree -> pos - left_tree -> pos) : 0;
        if (temp_result > result)
            result = temp_result;
        // we traverse along the boundary
        if (left_tree -> right != NULL)
            left_tree = left_tree -> right;
        else
            left_tree = left_tree -> left;
        if (right_tree -> left != NULL)
            right_tree = right_tree -> left;
        else
            right_tree = right_tree -> right;
    }
    return result;
}

void set_up_pos(node* root) {
    // no child nodes, root should be just pos 0
    if (root -> left == NULL && root -> right == NULL) {
        root -> pos = 0;
    // if just has left node, the root pos should be left node pos + 2 
    } else if (root -> left != NULL && root -> right == NULL) {
        set_up_pos(root -> left);
        root -> pos = root -> left -> pos + 1;
    // if just has right node, the root pos should be right node pos - 2
    // we have consider if the position is valid and if we need to shift right child
    } else if (root -> left == NULL && root -> right != NULL) {
        set_up_pos(root -> right);
        if (root -> right -> pos < 1) {
            int shift_pos = 1 - root -> right -> pos;
            shift_tree(root -> right, shift_pos);
        }
        root -> pos = root -> right -> pos - 1;
    } else {
        // here we have to calculate the minimum shift distance
        // we have left tree and right tree
        // we traverse the right bound of left tree and left bound of right tree layer by layer
        // left bound of right tree should be at least 2 further than right bound of left tree
        set_up_pos(root -> left);
        set_up_pos(root -> right);
        int shift_pos = calc_shift_pos(root -> left, root -> right);
        shift_tree(root -> right, shift_pos);
        // then the root pos should be the middle of left rooth and right root
        int left_tree_pos = root -> left -> pos;
        int right_tree_pos = root -> right -> pos;
        root -> pos = (left_tree_pos + right_tree_pos) / 2;
    }
}

// use a level order traversal on the tree
// the underscore represents an edge of a tree
// the node under the underscore in the next level is the children of the parent in current level
void draw_tree(node* root) {
    vector<node*> level;
    level.push_back(root);
    while (!level.empty()) {
        vector<node*> temp;
        int position = 0;
        for (int i = 0; i < level.size(); ++i) {
            node* current = level[i];
            node* left_child = current -> left;
            node* right_child = current -> right;
            int left_edge = 0;
            int right_edge = 0;
            if (left_child != NULL) {
                temp.push_back(left_child);
                left_edge = current -> pos - left_child -> pos;
            }
            if (right_child != NULL) {
                temp.push_back(right_child);
                right_edge = right_child -> pos - current -> pos;
            }
            // print left space
            int left_space = current -> pos - left_edge - position;
            for (int j = 0; j < left_space; ++j, ++position)
                cout << " ";
            // print left edge
            for (int j = 0; j < left_edge; ++j, ++position)
                cout << "_";
            // print node
            cout << current -> val;
            ++position;
            //print right edge
            for (int j = 0; j < right_edge; ++j, ++position)
                cout << "_";

        }
        cout << endl;
        level = temp;
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
/*
//     __1__
//    _2_ _3_
//    4 5 6 7
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node3 -> left = node6;
    node3 -> right = node7;
*/

/*
//   _1_
//  _2_3 
//  4_5_
//   6 7     
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> left = node4;
    node2 -> right = node5;
    node5 -> left = node6;
    node5 -> right = node7;
*/
//  ___1___
//  2_   _3
//   4_ _5
//    6 7
    node1 -> left = node2;
    node1 -> right = node3;
    node2 -> right = node4;
    node4 -> right = node6;
    node3 -> left = node5;
    node5 -> left = node7;

    set_up_pos(node1);
    draw_tree(node1);
}











