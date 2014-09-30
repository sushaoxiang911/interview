#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val;
    node* next;
};

// use a priority queue, a min heap to do that
// n is the total number of all the elements
// O(nlogn)

struct comp {
    bool operator() (const node* node1, const node* node2) {
        if (node1 -> val > node2 -> val)
            return true;
        else
            return false;
    }
};


node* merge_k_lists (vector<node*> lists) {
    priority_queue <node*, vector<node*>, comp> queue;
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] != NULL)
            queue.push(lists[i]);
    }
    
    node* last = NULL;
    node* result = NULL;
    
    while (!queue.empty()) {
        node* current_node = queue.top();
        queue.pop();
    
        if (last == NULL) 
            result = current_node;
        else {
            last -> next = current_node;
        }
        last = current_node;
        if (current_node -> next != NULL)
            queue.push(current_node -> next);
    }
    return result;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node* node4 = new node;
    node* node5 = new node;
    node* node6 = new node;
    node* node7 = new node;
    node* node8 = new node;
    node* node9 = new node;

    node1 -> val = 1;
    node2 -> val = 3;
    node3 -> val = 7;
    node4 -> val = 10;
    node5 -> val = 2;
    node6 -> val = 5;
    node7 -> val = 6;
    node8 -> val = 4;
    node9 -> val = 9;

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node5 -> next = node6;
    node6 -> next = node7;
    node8 -> next = node9;
    
    vector<node*> lists {node1, node5, node8};
    node* result = merge_k_lists(lists);
    node* it = result;
    while (it != NULL) {
        cout << it -> val << " ";
        it = it -> next;
    }
    cout << endl;

}

