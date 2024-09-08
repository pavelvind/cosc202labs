#include "C4Col.h"
#include <iostream>

using namespace std;

// constructor
C4Col::C4Col() {
    numDiscs = 0;
    maxDiscs = 6;
    for (int i = 0; i < maxDiscs; i++) {
        discs[i] = ' ';
    }
}

// checks if the column is full
bool C4Col::isFull() {
    return numDiscs == maxDiscs;
}

// returns the disc at a given index
char C4Col::getDisc(int index) {
    if (index >= 0 && index < numDiscs) {
        return discs[index];
    } else {
        return ' ';  // return a blank space for invalid indices
    }
}

// returns the maximum number of discs
int C4Col::getMaxDiscs() {
    return maxDiscs;
}
// return number of discs
int C4Col::getNumDiscs() {
    return numDiscs;
}

// adds a disc to the column
void C4Col::addDisc(char color) {
    if (color != 'X' && color != 'O') {
        cout << "You used the wrong char, use X or O only" << endl;
        return;
    }
    if (isFull()) {
        cout << "Column is full!" << endl;
        return;
    }
    discs[numDiscs] = color;
    numDiscs++;
}