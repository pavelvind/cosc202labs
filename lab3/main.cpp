/*  
Lab 3: Blackjack
Pavel Vinduska
netid pvindusk
student id 000697226
This program allows two players to play blackjack.
 */

#include "CardDeck.h"   // class definition for CardDeck used below

using namespace std;

int main() {
  CardDeck * deck;      // pointer to a single C4Board object
  deck = new CardDeck;  // dynamically allocates memory for a CardDeck object and calls the CardDeck constructor to initialize the deck

  // print carddeck ordered 
  cout << endl << "Printing ordered deck. " << endl;
  deck->print();  // Use '->' instead of '.' because 'deck' is a pointer to an object

  // print shuffled deck 
  cout << endl << "Printing shuffled deck. " << endl;
  deck->shuffle();
  deck->print();
  
}
