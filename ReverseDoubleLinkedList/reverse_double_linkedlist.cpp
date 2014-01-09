#include <iostream>

using namespace std;

struct node
{
    int value;
    node* prev;
    node* next;
};

// traverse 
node* dlink_reverse (node* p)
{
    node* t = NULL;
    while(p)
    {
        t = p;
        p = p -> next;
        t -> next = t -> prev;
        t -> prev = p;
    }
    return t;
}

int main()
{
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node1 -> value = 1;
    node2 -> value = 2;
    node3 -> value = 3;
    node4 -> value = 4;
    node1 -> prev = NULL;
    node1 -> next = node2;
    node2 -> prev = node1;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = NULL;

    node* head = dlink_reverse (node1);

    while (head != NULL)
    {
        cout << head -> value;
        head = head -> next;
    }
    cout << endl;
}
