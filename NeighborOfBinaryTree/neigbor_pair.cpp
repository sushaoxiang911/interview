#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct node
{
    node(): value(0),
            left(NULL),
            right(NULL),
            parent(NULL),
            neighbor(NULL){};
    int value;
    node* left;
    node* right;
    node* parent;
    node* neighbor;
};
// traverse all the nodes
void find_neighbor_pair (node* root)
{
    queue <node*> temp;
    temp.push (root);
    while (!temp.empty())
    {
        node* current = temp.front();
        temp.pop();
        if (current -> parent != NULL)
        {
            if (current == current -> parent -> left)
            {
                current -> neighbor = current -> parent -> right;
            }
            else
            {
                if (current -> parent -> neighbor != NULL)
                {
                    current -> neighbor = current -> parent -> neighbor -> left;
                }
            }
        }
        if (current -> left != NULL)
            temp.push(current -> left);
        if (current -> right != NULL)
            temp.push(current -> right);
    }
    
}
void test (node* root)
{
    if (root == NULL)
        return;
    test (root -> left);
    if (root -> neighbor != NULL)
    {
        cout << "(" << root -> value << ", " << root -> neighbor -> value << ")" << endl;
    }
    test (root -> right);
}


int main()
{
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
    node* node11 = new node;
    node* node12 = new node;
    node* node13 = new node;
    node* node14 = new node;
    node* node15 = new node;
    node1 -> value = 1;
    node2 -> value = 2;
    node3 -> value = 3;
    node4 -> value = 4;
    node5 -> value = 5;
    node6 -> value = 6;
    node7 -> value = 7;
    node8 -> value = 8;
    node9 -> value = 9;
    node10 -> value = 10;
    node11 -> value = 11;
    node12 -> value = 12;
    node13 -> value = 13;
    node14 -> value = 14;
    node15 -> value = 15;
    node1 -> left = node2;
    node2 -> parent = node1;
    node1 -> right = node3;
    node3 -> parent = node1;
    node2 -> left = node4;
    node4 -> parent = node2;
    node2 -> right = node5;
    node5 -> parent = node2;
    node3 -> left = node6;
    node6 -> parent = node3;
    node3 -> right = node7;
    node7 -> parent = node3;
    node4 -> left = node8;
    node8 -> parent = node4;
    node4 -> right = node9;
    node9 -> parent = node4;
    node5 -> left = node10;
    node10 -> parent = node5;
    node5 -> right = node11;
    node11 -> parent = node5;
    node6 -> left = node12;
    node12 -> parent = node6;
    node6 -> right = node13;
    node13 -> parent = node6;
    node7 -> left = node14;
    node14 -> parent = node7;
    node7 -> right = node15;
    node15 -> parent = node7;
    cout << "initial success" << endl;
    find_neighbor_pair (node1);
    cout << "function success" << endl;
    test (node1); 

}




