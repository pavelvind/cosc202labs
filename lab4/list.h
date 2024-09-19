#include <iostream>
#include <string>

using namespace std;

struct Node { 
        int data;
        Node* next;
        Node(int value) {
        
    }
        };
class List {

public:
void appendNode(const int &); // Pass by reference
void addList();              // Take two linked lists, representing two integers and return a new linked list 
~List();                    // Destructor of the list
void storeNumber(List &list, int num);

private:
Node* head;
string numStr;
};
