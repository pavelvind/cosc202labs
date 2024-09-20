#include <iostream>
#include <string>

using namespace std;



struct Node { 
        int data;
        Node* next;
        Node(int value);
        };

class List {

public:
void appendNode(const int &); // Pass by reference
void reverse();
void storeNumber( string num);
void print();
Node* getHead();
List addList(List& List1, List& List2);       // Take two linked lists -> return a new linked list 

// Rule of three

List();                      // Constructor
~List();                    // Destructor of the list
List(const List& other);  // Copy constructor
List& operator=(const List& other);  // Assignment operator

private:
Node* head;
string numStr;
};
