#include <iostream>

using namespace std;

struct node
{
    node(): val(0),
            right(NULL),
            left(NULL){};
    int val;
    node* right;
    node* left;
};

int maxheight (node* p)
{
    if (!p) return 0;
    int leftheight  = maxheight(p -> left);
    int rightheight = maxheight(p -> right);
    return (leftheight > rightheight) ? leftheight+1 : rightheight+1;
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
    node3 -> left = node6;
    node5 -> left = node7;

    cout << maxheight (node1) << endl;
}
