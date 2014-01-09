#include <iostream>

using namespace std;

struct node
{
    node(): value(0),
            next(NULL){};
    int value;
    node* next;
};

bool is_cyclic(node* head)
{
    node* ptr1 = head;
    node* ptr2 = head;
    while (ptr2 != NULL)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
        if (ptr1 == ptr2)
            return true;
    }
    return false;
}

node* find_cycle_begin (node* head)
{
    node* ptr1 = head;
    node* ptr2 = head;
    while (ptr2 != NULL)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
        if (ptr1 == ptr2)
            break;
    }
    ptr2 = head;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return ptr1;
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
    node1 -> value = 1;
    node2 -> value = 2;
    node3 -> value = 3;
    node4 -> value = 4;
    node5 -> value = 5;
    node6 -> value = 6;
    node7 -> value = 7;
    node8 -> value = 8;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = node7;
    node7 -> next = node8;
    node8 -> next = node4;
    cout << is_cyclic(node1) << endl;
    node* begin = find_cycle_begin (node1);
    cout << begin -> value << endl;
}
