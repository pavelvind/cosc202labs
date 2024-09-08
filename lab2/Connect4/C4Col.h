#ifndef C4COL_H
#define C4COL_H

class C4Col {
private:
    int maxDiscs;         // Maximum number of discs
    int numDiscs;         // Current number of discs
    char discs[6];        // Array to store discs
    
    

public:
    C4Col();              // Default constructor
    bool isFull();        // Checks if the column is full
    char getDisc(int index);  // Returns the disc at a given index
    int getMaxDiscs();    // Returns the max number of discs
    void addDisc(char color); // Adds a disc to the column
    int getNumDiscs();    // return number of discs
};

#endif