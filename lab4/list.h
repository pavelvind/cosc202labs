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
List addList(List& List1, List& List2);             // Take two linked lists, representing two integers and return a new linked list 

List();                      // Constructor
~List();                    // Destructor of the list

private:
Node* head;
string numStr;
};
