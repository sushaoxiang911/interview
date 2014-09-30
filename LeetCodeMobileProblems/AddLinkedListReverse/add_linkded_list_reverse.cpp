#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;
};

// iteration
node* add_linked_list_reverse (node* list1, node* list2) {
    node* result = NULL;
    node* tail = NULL;

    node* temp1 = list1;
    node* temp2 = list2;
    
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL) {
        int sum = carry + temp1 -> value + temp2 -> value;
        node* temp = new node;
        if (result == NULL) {
            result = temp;
            tail = temp;
        }
        temp -> value = sum % 10;
        carry = sum / 10;
        tail -> next = temp;
        tail = temp;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    while (temp1 != NULL) {
        int sum = carry + temp1 -> value;
        node* temp = new node;
        if (result == NULL) {
            result = temp;
            tail = temp;
        }
        temp -> value = sum % 10;
        carry = sum / 10;
        tail -> next = temp;
        tail = temp;
        temp1 = temp1 -> next;
    }

    while (temp2 != NULL) {
        int sum = carry + temp2 -> value;
        node* temp = new node;
        if (result == NULL) {
            result = temp;
            tail = temp;
        }
        temp -> value = sum % 10;
        carry = sum / 10;
        tail -> next = temp;
        tail = temp;
        temp2 = temp2 -> next;
    }
    
    if (carry != 0) {
        node* temp = new node;
        temp -> value = carry;
        tail -> next = temp;
        tail = temp;
    }

    return result;

}

// recursion
node* add_linked_list_reverse_2 (node* list1, node* list2, int carry) {
    if (list1 == NULL && list2 == NULL && carry == 0)
        return NULL;
    else if (list1 == NULL && list2 == NULL && carry > 0) {
        node* temp = new node;
        temp -> value = carry;
        temp -> next = NULL;
        return temp;
    } else if (list1 == NULL && list2 != NULL) {
        int sum = list2 -> value + carry;
        node* temp = new node;
        temp -> value = sum % 10;
        temp -> next = add_linked_list_reverse_2(NULL, list2 -> next, sum / 10);
        return temp;
    } else if (list1 != NULL && list2 == NULL) {
        int sum = list1 -> value + carry;
        node* temp = new node;
        temp -> value = sum % 10;
        temp -> next = add_linked_list_reverse_2(list1 -> next, NULL, sum / 10);
        return temp;
    } else {
        int sum = list1 -> value + list2 -> value + carry;
        node* temp = new node;
        temp -> value = sum % 10;
        temp -> next = add_linked_list_reverse_2(list1 -> next, list2 -> next, sum / 10);
        return temp;
    }
}



int main() {

    node* list1 = NULL;

    node* temp = new node;
    temp -> value = 9;
    temp -> next = list1;
    list1 = temp;

    temp = new node;
    temp -> value = 2;
    temp -> next = list1;
    list1 = temp;

    temp = new node;
    temp -> value = 4;
    temp -> next = list1;
    list1 = temp;

    temp = new node;
    temp -> value = 3;
    temp -> next = list1;
    list1 = temp;

    node* list2 = NULL;

    temp = new node;
    temp -> value = 1;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 5;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 6;
    temp -> next = list2;
    list2 = temp;

    temp = new node;
    temp -> value = 4;
    temp -> next = list2;
    list2 = temp;

    //node* result = add_linked_list_reverse(list1, list2);
    node* result = add_linked_list_reverse_2(list1, list2, 0);
    temp = result;  
  

    cout << "result: ";
    while (temp != NULL) {
        cout << temp -> value;
        temp = temp -> next;
    }
    cout << endl;
}





