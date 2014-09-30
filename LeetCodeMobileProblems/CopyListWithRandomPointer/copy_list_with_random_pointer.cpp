#include <iostream>
#include <map>

using namespace std;

struct node {
    int val;
    node* next;
    node* random;
};

node* deep_copy(node* ptr) {
    if (ptr == NULL)
        return NULL;
    map<node*, node*> path;

    node* result = new node;
    result -> val = ptr -> val;
    node* current = ptr;
    node* current_cp = result;
    
    path.insert(pair<node*, node*>(ptr, result));   

    while (current != NULL) {
        node* next = current -> next;
        if (next == NULL)
            current_cp -> next = NULL;
        else {
            auto it = path.find(next);
            if (it == path.end()) {
                node* new_next = new node;
                new_next -> val = next -> val;
                current_cp -> next = new_next;
            } else {
                current_cp -> next = it -> second;
            }
        }
        node* random = current -> random;
        if (random == NULL) {
            current_cp -> random = NULL;
        } else {
            auto it = path.find(random);
            if (it == path.end()) {
                node* new_random = new node;
                new_random -> val = random -> val;
                current_cp -> random = new_random;
            } else {
                current_cp -> random = it -> second;
            }
        }
        current = current -> next;
        current_cp = current_cp -> next;
    }
    return result;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;

    node1 -> val = 1;
    node1 -> next = node2;
    node2 -> val = 2;
    node2 -> next = node3;
    node3 -> val = 3;
    node3 -> next = node4;
    node4 -> val = 4;
    node4 -> next = node5;
    node5 -> val = 5;
    node5 -> next = NULL;

    node1 -> random = node1;
    node2 -> random = NULL;
    node3 -> random = node1;
    node4 -> random = node3;
    node5 -> random = node2;

    node* node1_cp = deep_copy (node1);

    cout << "node1:" << node1_cp -> val  <<endl;
    if (node1_cp -> next)
        cout << "node1 next: " << node1_cp -> next -> val << endl;
    else
        cout << "node1 next: " << "NULL" << endl;
    if (node1_cp -> random)
        cout << "node1 random: " << node1_cp -> random -> val << endl;
    else 
        cout << "node1 random: " << "NULL" << endl;
    node* node2_cp = node1_cp -> next;
    
    cout << "node2:" << node2_cp -> val  <<endl;
    if (node2_cp -> next)
        cout << "node2 next: " << node2_cp -> next -> val << endl;
    else
        cout << "node2 next: " << "NULL" << endl;
    if (node2_cp -> random)
        cout << "node2 random: " << node2_cp -> random -> val << endl;
    else 
        cout << "node2 random: " << "NULL" << endl;
    node* node3_cp = node2_cp -> next;
    
    cout << "node3:" << node3_cp -> val  <<endl;
    if (node3_cp -> next)
        cout << "node3 next: " << node3_cp -> next -> val << endl;
    else
        cout << "node3 next: " << "NULL" << endl;
    if (node1_cp -> random)
        cout << "node3 random: " << node3_cp -> random -> val << endl;
    else 
        cout << "node3 random: " << "NULL" << endl;
    node* node4_cp = node3_cp -> next;

    cout << "node4:" << node4_cp -> val  <<endl;
    if (node4_cp -> next)
        cout << "node4 next: " << node4_cp -> next -> val << endl;
    else
        cout << "node4 next: " << "NULL" << endl;
    if (node4_cp -> random)
        cout << "node4 random: " << node4_cp -> random -> val << endl;
    else 
        cout << "node4 random: " << "NULL" << endl;
    node* node5_cp = node4_cp -> next;
    
    cout << "node5:" << node5_cp -> val  <<endl;
    if (node5_cp -> next)
        cout << "node5 next: " << node5_cp -> next -> val << endl;
    else
        cout << "node5 next: " << "NULL" << endl;
    if (node5_cp -> random)
        cout << "node5 random: " << node5_cp -> random -> val << endl;
    else 
        cout << "node5 random: " << "NULL" << endl;
}

