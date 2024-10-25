#ifndef SLIDE_PUZZLE
#define SLIDE_PUZZLE


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 2D vector vector<vector<int>> board;
// Use blank spot as 16 but display 'X'

class SlidePuzzle{

public:
    void initialize();
    void isValid();         // Not every board is valid
    void finalCheck(); 
    void swap();
    void validMove();

private:
    vector <vector<int>> board;
    // I decided to use just 1d vector
};

#endif