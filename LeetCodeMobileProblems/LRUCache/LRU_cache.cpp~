#include <iostream>
#include <map>

using namespace std;

// use a doubly linked list to save all the result
// a map with key and linked list node pointer
// doubly linked list is regarded as a queue

struct node {
    node* prev;
    node* next;
    
    int key;
    int value;
};

class cache {

private:
    node* start;
    node* end;
    int size;
    int capacity;
    
    map<int, node*> search_map;
    
    void recent_use (node* result) {
        result -> prev = NULL;
        result -> next = head;
        start = result;
    }

     
public:
    cache (int cap) : start(NULL), end(NULL), size(0), capacity(cap) {}
    
    int get (int k) {
        auto it = search_map.find(k);
        if (it == search_map.end())
            return -1;
        else {
            node* result = it -> second;
            result -> prev -> next = result -> next;
            result -> next -> prev = result -> prev;
            recent_use(result);
            return start -> value;
        }
    }

    void set (int k, int v) {
        auto it = search_map.find(k);
        if (it == search_map.end()) {
            node* temp = new node;
            temp -> key = k;
            temp -> value = v;
            recent_use (temp);
            if (size < capacity)
                ++size;
            else {
                node* temp = end;
                end = temp -> prev;
                end -> next = NULL;
                delete temp;
            }
        } else {
            node* result = it -> second;
            result -> prev -> next = result -> next;
            result -> next -> prev = result -> prev;
            recent_use(result);
        }
    }  
    

};


