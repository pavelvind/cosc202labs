#ifndef BOARD_H
#define BOARD_H

#include <string>   // include some elements of the STL
#include <vector>  

using namespace std;

typedef std::vector<bool> Bool1D;    // define a 1D vector of bools
typedef std::vector<Bool1D> Bool2D;  // define a 2D vector using 1D vector
typedef std::vector<Bool2D> Bool3D;  // define a 3D vector using a 2D vector


class Board{

 public:

  Board();   // constructor
  bool place_ship(char, int, int, int, char, bool);    // places a ship on the board, returns true if successful
  void place_random(char, int);        // places a ship on the board at random
  void randomStart();                  // generate a board at random (e.g., enemy player)
  bool fire(char, int, bool);          // fire!! 
  bool amKaput();                      // one... last... breath.... returns true if game is over
  void printMine();                    // print my board
  void printEnemy();                   // print enemies board 
  void printStats();                   // print game statistics (hits, misses)
  bool wasTested(char, int);           // checks to see if a specific spot was tested
  
 private:
  int numShips;                        // number of ships in game
  int boardSize;                       // size of board
  int placedShips;                     // number of ships on the board
  int numHits;                         // number of spots on a ship hit
  int numMisses;                       // number of misses
  int shipsSunk;                       // number of ships sunk
  vector<vector<char> > pieces;        // the board
  Bool3D test;                         // used to see if a spot was tested

};

#endif
