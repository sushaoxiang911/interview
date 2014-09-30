#include <iostream>
#include <vector>
#include <map>
#include <queue>


// breadth first search
// use a map to check if the node has already been expanded
// and to check if there is a loop an we need to find the copy node generated before
using namespace std;

struct node {
    int id;
    vector<node*> neighbors;
};

node* clone_graph (node* entrance) {
    if (entrance == NULL)
        return NULL;
    map<node*, node*> record;
    queue<node*> q;
    q.push(entrance);
    // entrance
    node* result = new node;
    result -> id = entrance -> id;
    record.insert(pair<node*, node*>(entrance, result));
    while (!q.empty()) {
        node* current_node = q.front();
        auto it = record.find(current_node);
        node* current_copy = it -> second;
        q.pop();
        vector<node*> current_neighbors = current_node -> neighbors;
        for (int i = 0; i < current_neighbors.size(); ++i) {
            node* temp_neighbor = current_neighbors[i];
            auto it = record.find(temp_neighbor);
            if (it == record.end()) {
                node* temp_copy = new node;
                temp_copy -> id = temp_neighbor -> id;
                current_copy -> neighbors.push_back(temp_neighbor);
                record.insert(pair<node*, node*>(temp_neighbor, temp_copy));
                q.push(temp_neighbor);
            } else {
                current_copy -> neighbors.push_back(it -> second);
            }
        }
    }
    return result;
}

int main() {
    node* node1 = new node;
    node* node2 = new node;
    node* node3 = new node;
    node1 -> id = 1;
    node2 -> id = 2;
    node3 -> id = 3;
    node1 -> neighbors.push_back(node2);
    node1 -> neighbors.push_back(node3);
    node2 -> neighbors.push_back(node3);
    node3 -> neighbors.push_back(node1);
    node3 -> neighbors.push_back(node3);

    node* copy_node1 = clone_graph(node1);
    cout << "copy_node1 id: " << copy_node1 -> id << endl;
    cout << "copy_node1 neighbors: " << endl;
    for (int i = 0; i < copy_node1 -> neighbors.size(); ++i) {
        cout << copy_node1 -> neighbors[i] -> id << " ";
    }
    cout << endl;
    node* copy_node2 = copy_node1 -> neighbors[0];
    node* copy_node3 = copy_node1 -> neighbors[1];
    cout << "copy_node2 id: " << copy_node2 -> id << endl;
    cout << "copy_node2 neighbors: " << endl;
    for (int i = 0; i < copy_node2 -> neighbors.size(); ++i) {
        cout << copy_node2 -> neighbors[i] -> id << " ";
    }
    cout << endl;
    
    cout << "copy_node3 id: " << copy_node3 -> id << endl;
    cout << "copy_node3 neighbors: " << endl;
    for (int i = 0; i < copy_node3 -> neighbors.size(); ++i) {
        cout << copy_node3 -> neighbors[i] -> id << " ";
    }
    cout << endl;
}





