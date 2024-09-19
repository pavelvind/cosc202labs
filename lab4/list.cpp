#include "list.h"

// Destructor for linkedList
List::~List(){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;}
}

// Add node to the back
void List::appendNode(const int &value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        newNode = head;
    }
    else{
        Node* temp = head;
        while(temp != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

// Store number to linkedlist function 
void List::storeNumber(List &list, int num){ // cin << num1 << num2;
    numStr = to_string(num);
    for(int i = 0; i < numStr.size(); i++){
        int digit = numStr[i] - '0'; // ASCII table
        list.appendNode(digit);
    }
}