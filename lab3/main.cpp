/*  
Lab 3: Blackjack
Pavel Vinduska
netid pvindusk
student id 000697226
This program allows two players to play blackjack.
 */

#include "CardDeck.h"   // class definition for CardDeck used below
#include <iomanip>

using namespace std;


void play(CardDeck& deck) {

    char hitOrStand;
    int playerScore = 0;
    int dealerScore = 0;
    vector<int> playerHand;
    vector<int> dealerHand;

    // Interactive loop
    bool gameOver = false;
    while (!gameOver) {
        // Deal a card to the player
        
        // Card 0
        playerHand.push_back(deck.deal());
        // Card 1
        playerHand.push_back(deck.deal());

        // Card 2
        dealerHand.push_back(deck.deal());
        // Card 3
        dealerHand.push_back(deck.deal());

        int playerStartHand = playerHand[0]+playerHand[1];
        int dealerStartHand = dealerHand[0]+dealerHand[1];

        cout << "Player total hand:" << playerHand[0]+playerHand[1] << endl;
        cout << "Dealer total hand:" << dealerHand[0]+dealerHand[1] << endl;

        cout << "Player: Hit or Stand (Type 'h' or 's')?" << endl;
        cin >> hitOrStand;

        while(hitOrStand = 'h'){

          cout << "Player chose t hit!" << endl;
        }

        

    }

}

int main() {
  CardDeck * deck;      
  deck = new CardDeck;  // dynamically allocates memory for a CardDeck object and calls the CardDeck constructor to initialize the deck

  // print carddeck ordered 
  cout << endl << "Printing ordered deck. " << endl;
  deck->print();  // Use '->' instead of '.' because 'deck' is a pointer to an object

  // print shuffled deck 
  cout << endl << "Printing shuffled deck. " << endl;
  deck->shuffle();
  deck->print();

  play(*deck);

  
  
}