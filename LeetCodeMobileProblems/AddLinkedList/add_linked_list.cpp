#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;
};

// obtain numbers from the node and than convert the result to a new linked list
// maybe out of int bound
// all are linear complexity
node* add_linked_list_1 (node* list1, node* list2) {
    int num1 = 0;
    int num2 = 0;
    
    node* temp = list1;
    while (temp != NULL) {
        num1 = num1 * 10 + temp -> value;
        temp = temp -> next;  
    }
    temp = list2;
    while (temp != NULL) {
        num2 = num2 * 10 + temp -> value;
        temp = temp -> next;
    }
    int result_num = num1 + num2;
    
    node* result = NULL;
    while (result_num != 0) {
        node* temp = new node;
        int num = result_num % 10;
        temp -> value = num;
        temp -> next = result;
        result = temp;
        result_num = result_num / 10;
    }
    return result;
}
// use recursion to do that
// have to guarantee that two numbers have the same length
// one can recurse by the node and rewrite carry
// one can recurse by the carry and pass result argument
node* add_linked_list_2_helper (node* list1, node* list2, int& carry) {
    if (list1 == NULL) 
        return NULL;
    node* temp = new node;
    temp -> next = add_linked_list_2_helper(list1 -> next, list2 -> next, carry);
    int sum = list1 -> value + list2 -> value + carry;
    temp -> value = sum % 10;
    carry = sum / 10;
    return temp; 
}

node* add_linked_list_2 (node* list1, node* list2) {
    int len1 = 0;
    int len2 = 0;
    node* temp = list1;
    while (temp != NULL) {
        temp = temp -> next;
        ++len1;
    }
    temp = list2;
    while (temp != NULL) {
        temp = temp -> next;
        ++len2;
    }    
    if (len1 < len2) {
        int zero_num = len2 - len1;
        for (int i = 0; i < zero_num; ++i) {
            temp = new node;
            temp -> value = 0;
            temp -> next = list1;
            list1 = temp;
        }
    }
    if (len2 < len1) {
        int zero_num = len1 - len2;
        for (int i = 0; i < zero_num; ++i) {
            temp = new node;
            temp -> value = 0;
            temp -> next = list2;
            list2 = temp;
        }
    }
    
    int carry = 0;
    node* result = add_linked_list_2_helper(list1, list2, carry);
    if (carry > 0) {
        temp = new node;
        temp -> value = carry;
        temp -> next = result;
        result = temp;
    }
    return result;
}   

int main() {

    node* list1 = NULL;
    
    node* temp = new node;
    temp -> value = 3;
    temp -> next = list1;
    list1 = temp;

    temp = new node;
    temp -> value = 4;
    temp -> next = list1;
    list1 = temp;

    temp = new node;
    temp -> value = 2;
    temp -> next = list1;
    list1 = temp;
   
    temp = new node;
    temp -> value = 9;
    temp -> next = list1;
    list1 = temp;

    node* list2 = NULL;
    
    temp = new node;
    temp -> value = 4;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 6;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 5;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 1;
    temp -> next = list2;
    list2 = temp;

    //node* result = add_linked_list_1 (list1, list2);
    node* result = add_linked_list_2 (list1, list2);
    
    cout << "result: ";
    temp = result;
    while (temp != NULL) {
        cout << temp -> value;
        temp = temp -> next;
    }
    cout << endl;
}



