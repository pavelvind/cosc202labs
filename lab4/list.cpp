#include "list.h"
// List constructor
List::List(){
    head = nullptr;
}

// Node cosntructor
Node::Node(int value) {
        data = value;
        next = nullptr;     
    }



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
        head =newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

// Store number to linkedlist function (456 = 6 -> 5 -> 4 -> null_ptr)
void List::storeNumber(List &list, int num){ // cin << num1 << num2;
    numStr = to_string(num);
    for(int i = numStr.size() - 1; i > -1 ; i--){
        int digit = numStr[i] - '0'; // ASCII
        list.appendNode(digit);
    }
}

// Reverse function


// Print fucntion
void List::print(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}


// Sum the numbers
List List::addList(List& List1, List& List2){
   
    Node* temp1 = List1.head;
    Node* temp2 = List2.head;
    List result;

    // If both lists are not empty
    

    return result;

}
