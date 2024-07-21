#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include "board.h"

using namespace std;

// constructor
Board::Board() : pieces (20, 20), test  (20, Bool2D(20, Bool1D(20))) {

  int i, j;

  for (i = 1; i <= 10; i++)       // initialize the board with o chars
    for (j = 1; j <= 10; j++)
      pieces[i][j] = 'o';

  numShips = 0;     // initialize variables
  boardSize = 10;
  placedShips = 0;
  numHits = numMisses = shipsSunk = 0;
   
}

// place a ship in a specific location
bool Board::place_ship(char col, int row, int orient, int size, 
		       char type, bool verbose) {

  int i, hits;
  int val = toupper(col) - 'A' + 1;  // convert letter to number
  
  // check if the location is on the board
  if ((val < 1 || val > boardSize) || (row < 1 || row > boardSize)) {

    if (verbose)
      cout << "Invalid spot.  Please reenter" << endl << endl;
    return (false);

  }


  if (orient == 0) {   // horizontal orientation

    int end = row + size - 1;  // calculate end of ship
    
    if (end <= boardSize) {

      hits = 0;
      for (i = 0; i < size; i++) {
 
	if (pieces[i + row][val] != 'o')
	  hits++;

      }

      if (hits > 0) {   // ship overlaps with another

	if (verbose) {
	  cout << "Invalid spot.  This ship overlaps with a previous ship.  Please reenter";
	  cout << endl << endl;

	}

	return (false);

      }

      for (i = 0; i < size; i++)      // fill in character board with ship id
	pieces[i + row][val] = type;


    }
    else {   // piece falls off board

      if (verbose)
	cout <<" Invalid spot, piece will not fit.  Please reenter" << endl << endl;

      return (false);

    }

  }
  else {   // vertical orientation

    int end = val + size - 1;
    
    if (end <= boardSize) {

      hits = 0;
      for (i = 0; i < size; i++) {

	if (pieces[row][val + i] != 'o')
	  hits++;

      }

      if (hits > 0) {   // overlaps with other ship

	if (verbose) {
	
	  cout << "Invalid spot.  This ship overlaps with a previous ship.  Please reenter";
	  cout << endl << endl;

	}

	return (false);

      }

      for (i = 0; i < size; i++) 
	pieces[row][val + i] = type;

    }
    else {

      if (verbose) 
	cout <<" Invalid spot, piece will not fit.  Please reenter" << endl << endl;
	
      return (false);

    }

  }

  numShips++;             // increment relevant variables
  placedShips += size;
  return (true);     // return success

}

// place a ship in a random location
void Board::place_random(char type, int size) {

  bool res;
  char col;
  int row, orient;

  do {

    col = rand() % 10 + 'A';   // generate random col
    row = rand() % 10 + 1;     // generate random row
    orient = rand() % 2;
    
    // output random data
    cout << col << "  " << row << "  " << orient << endl;

    // place ship
    res = place_ship(col, row, orient, size, type, false);
    
  } while (res == false);   // loop until success

}

void Board::randomStart() {

  place_random('C', 5);
  place_random('B', 4);
  place_random('R', 3);
  place_random('S', 3);
  place_random('D', 2);

}

bool Board::fire (char col, int row, bool verbose) {

  int val = toupper(col) - 'A' + 1;

  if (pieces[row][val] == 'o') {

    if (verbose)
      cout << "Miss..." << endl << endl;

    numMisses++;
    pieces[row][val] = '.';
    
    return (false);

  }
  else if (pieces[row][val] != '.' && pieces[row][val] != '*') {

    if (verbose)
      cout << "Hit!  Ship type: " << pieces[row][val] << endl << endl;

    numHits++;
    pieces[row][val] = '*';

    return (true);

  }
    
}
 
bool Board::amKaput() {

  return (numHits == placedShips);

}

void Board::printMine() {

  int i, j;
  char val;

  for (j = 1; j <= boardSize; j++) {
    val = 'A' + j - 1;
    cout << "=" << val;
  }

  for (i = 1; i <= boardSize; i++) {
   
    cout << "=" << endl << "|";

    for (j = 1; j <= boardSize; j++)
      cout << pieces[i][j] << "|";

    cout << " " << i << endl;

     for (j = 1; j <= boardSize; j++)
      cout << "==";

  }

  cout << endl;

}

void Board::printEnemy() {

  int i, j;
  char val;

  for (j = 1; j <= boardSize; j++) {
    val = 'A' + j - 1;
    cout << "=" << val;
  }

  for (i = 1; i <= boardSize; i++) {
   
    cout << "=" << endl << "|";

    for (j = 1; j <= boardSize; j++) {

      if ( pieces[i][j] == '*' ||  pieces[i][j] == '.')
	cout << pieces[i][j] << "|";
      else
	cout << "o|";

    }

    cout << " " << i << endl;

     for (j = 1; j <= boardSize; j++)
      cout << "==";

  }

  cout << endl;

}

void Board::printStats() {

  cout << "Ships: " << numShips << endl;
  cout << "Hits:  " << numHits << endl;
  cout << "Misses: " << numMisses << endl << endl;

}

bool Board::wasTested(char col, int row) {

  int val = toupper(col) - 'A' + 1;

  return (pieces[row][val] == '.' || pieces[row][val] == '*');

}
  
