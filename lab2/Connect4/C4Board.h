#ifndef C4BOARD_H
#define C4BOARD_H

#include "C4Col.h" 

#include <iostream>

class C4Board {

private: 
  C4Col board[7];       // array of C4Col objects representing each column on the board
  bool checkWinner(int);
  int row;              // keeps track of the row where the last disc was placed
  void getDiscPosition(int &row, int &col);
  static const int numRows = 6;
  static const int numCols = 7; 
  C4Col c4colArray[numCols];  
  bool gameOver = false; 
  int xStreak = 0;      // used for play function to decide who won
  int oStreak = 0;      // used for play function to decide who won
  int connected = 4;    // used for play function to decide who won
  int col;              // player input


 public:

  C4Board();            // default constructor
  void display();
  void play();
  
};
#endif