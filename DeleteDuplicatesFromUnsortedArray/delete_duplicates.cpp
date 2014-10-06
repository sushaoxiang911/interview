#include <iostream>
#include <set>

using namespace std;

struct node {
    int val;
    node* next;
};

// with set
void remove_duplicates(node* head) {
    if (head == NULL)
        return;
    
    node* cursor = head;
    node* previous = NULL;
    
    set<int> track;    

    while (cursor != NULL) {
        int current_val = cursor -> val;
        auto it = track.find(current_val);
        if (it == track.end()) {
            previous = cursor;
            cursor = cursor -> next;
            track.insert(current_val);
        } else {
            cursor = cursor -> next;
            previous -> next = cursor;
        }
    }
}

// do not use set
void remove_duplicates_2(node* head) {
    if (head == NULL) 
        return;
    
    node* cursor = head;
    while (cursor != NULL) {
        int current_val = cursor -> val;
        node* check = cursor -> next;
        node* prev = cursor;
        while (check != NULL) {
            if (check -> val == current_val) {
                prev -> next = check -> next;
                check = check -> next;
            } else {
                prev = check;
                check = check -> next;
            }
        }
        cursor = cursor -> next;
    }
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    
    node1 -> val = 1;
    node2 -> val = 3;
    node3 -> val = 1;
    node4 -> val = 4; 
    node5 -> val = 3;
   
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
 
    remove_duplicates_2(node1);
    
    node* temp = node1;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
    
}
