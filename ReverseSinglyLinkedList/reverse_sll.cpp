#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};

node* reverse (node* head)
{
    node* t = NULL;
    node* tp = NULL;
    while(head)
    {
        tp = t;
        t = head;
        head = head -> next;
        t -> next = tp;
    }
    return t;
}

node* reverse_help (node* rest, node* reversed)
{
    node* current;
    if (rest == NULL)
        return reversed;
    current = rest;
    rest = rest -> next;
    current -> next = reversed;
    return reverse_help (rest, current);
}

node* reverse_recursion (node* head)
{
    return reverse_help (head, NULL);
}


int main()
{
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node1 -> value = 1;
    node2 -> value = 2;
    node3 -> value = 3;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;
//    node* return_node = reverse(node1);
    node* return_node = reverse_recursion (node1);
    node* temp = return_node;
    while (temp != NULL)
    {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}


