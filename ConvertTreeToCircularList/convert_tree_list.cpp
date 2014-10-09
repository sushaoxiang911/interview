#include <iostream>

using namespace std;

struct node {
    int val;
    node* left_prev;
    node* right_next;
};



node* convert(node* root) {
    if (root -> left_prev == NULL && root -> right_next == NULL) {
        root -> right_next = root;
        root -> left_prev = root;
        return root;    
    }

    if (root -> left_prev != NULL && root -> right_next == NULL) {
        node* head = convert(root -> left_prev);
        root -> right_next = head;
        head -> left_prev -> right_next = root;
        root -> left_prev = head -> left_prev;
        head -> left_prev = root;
        return head;
    }

    if (root -> left_prev == NULL && root -> right_next != NULL) {
        node* head = convert(root -> right_next);
        root -> right_next = head;
        root -> left_prev = head -> left_prev;
        head -> left_prev = root;
        head -> left_prev -> right_next = root;
        return root;
    }
    
    node* head1 = convert(root -> left_prev);
    node* head2 = convert(root -> right_next);
    
    root -> left_prev = head1 -> left_prev;
    root -> right_next = head2;
    
    head1 -> left_prev -> right_next = root;
    head2 -> left_prev -> right_next = head1;
    
    head1 -> left_prev = head2 -> left_prev;
    head2 -> left_prev = root;
        
    return head1;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    
    node1 -> val = 5;
    node2 -> val = 4;
    node3 -> val = 7;
    node4 -> val = 3;
    node5 -> val = 6;

    node1 -> left_prev = node2;
    node1 -> right_next = node3;
    node2 -> left_prev = node4;
    node3 -> left_prev = node5;
    
    node* head = convert(node1);
    
    cout << "result: " << endl;
    node* temp = head;
    for (int i = 0; i < 10; ++i) {
        cout << temp -> val << " ";
        temp = temp -> right_next;
    }
    cout << endl;
    temp = head -> left_prev;
    for (int i = 0; i < 10; ++i) {
        cout << temp -> val << " ";
        temp = temp -> left_prev;
    }

    cout << endl;

}
