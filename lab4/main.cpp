/* Lab 04: Adding List-Based Integers
Pavel Vinduska
Used notes by dr. Scott: https://web.eecs.utk.edu/~semrich/cs202-24f/notes/7/index.html
Youtube: https://youtu.be/o5wJkJJpKtM?si=GWTLobwHsbe8sm8Q
*/ 

#include "list.h"

int main(int argc, char *argv[]) {
    string num1Str, num2Str;
    
    // Load numbers
    while(cin >> num1Str >> num2Str){
    List List1, List2;

    // Add them to linked list
    List1.storeNumber(num1Str);
    List2.storeNumber(num2Str);

    //List1.print();
    //List2.print();

    // Sum the numbers (lists)
    List result = List1.addList(List1, List2);    
    result.List::reverse();
    result.print();
    
    // Clear lists for next iteration
    List1 = List();
    List2 = List();
    }

    return 0;
}





