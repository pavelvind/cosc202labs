// Lab 04: Adding List-Based Integers
#include "list.h"

int main(int argc, char *argv[]) {
    string num1Str, num2Str;
    List List1, List2;
    while(cin >> num1Str >> num2Str){
    

    // Add them to linked list

    
    List1.storeNumber(num1Str);
    List2.storeNumber(num2Str);

    //List1.print();
    //List2.print();

    List result = List1.addList(List1, List2);    
    result.List::reverse();
    result.print();
    
    // Clear lists for next iteration
    List1 = List();
    List2 = List();
    }

    return 0;
}




