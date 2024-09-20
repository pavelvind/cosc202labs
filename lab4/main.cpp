// Lab 04: Adding List-Based Integers
#include "list.h"

int main(int argc, char *argv[]) {


    // Load the numbers
    int num1;
    int num2;
    cin >> num1 >> num2;

    // Add them to linked list
    List List1;
    List List2;

    
    List1.storeNumber(List1, num1);
    List2.storeNumber(List2, num2);

    List1.print();
    List2.print();

    

    return 0;
}


