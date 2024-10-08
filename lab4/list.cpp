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
    //cout << "Destructor" << endl;
}

// Copy constructor
List::List(const List& other) {
    head = nullptr;  

    if (other.head == nullptr) {
        head = nullptr;
    } else {
        // Copy the first node
        head = new Node(other.head->data);
        Node* current = head;
        Node* otherCurrent = other.head->next;

        // Copy the rest of the nodes
        while (otherCurrent != nullptr) {
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}

// Assignemnt operator
List& List::operator=(const List& other) {
    
    // If self-assignment
    if (this != &other) {  
        // Delete Nodes
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;  

        // Copy nodes from the 'other' list
        if (other.head != nullptr) {
            // Copy the first node
            head = new Node(other.head->data);
            current = head;
            Node* otherCurrent = other.head->next;

            // Copy the rest of the nodes
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
        
    }
    return *this;  
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
void List::storeNumber(string num){ // cin << num1 << num2;
    //numStr = to_string(num);
    for(int i = num.size() - 1; i > -1 ; i--){
        
        int digit = num[i] - '0'; // ASCII
        appendNode(digit);
    }
}

// Reverse function
void List::reverse(){
    
    Node* prev = nullptr;
    Node* temp = head;
    Node* next = nullptr;
    while(temp != nullptr){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        
    }
    head = prev;
}

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
    int carry = 0;

    while ((temp1 != nullptr) || (temp2 != nullptr) || (carry != 0)) {
        int sumDigit = carry;

        // Add data from List1 if temp1 is not empty
        if (temp1 != nullptr) {
            sumDigit += temp1->data;
            temp1 = temp1->next;  
        }

        // Add data from List2 if temp2 is not em[ty]
        if (temp2 != nullptr) {
            sumDigit += temp2->data;
            temp2 = temp2->next;  
        }

        // When sum is >=10 carry++
        carry = sumDigit / 10;
        
        // Append the last digit of sumDigit to the result
        result.appendNode(sumDigit % 10);
    }
    return result;
}
