/*  
Lab 2: Connect-four
Pavel Vinduska
netid pvindusk
student id 000697226
This program allows two players to play connect four.
It determines the winner after each turn and displays the board.
 */
#include "C4Board.h"   // class definition for C4Board used below
#include <iostream>

int main() {
  C4Board c4;         // instantiate an instance of a C4Board object

  c4.play();          // play game!!
  return 0;
}
