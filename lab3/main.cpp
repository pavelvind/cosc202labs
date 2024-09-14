/*  
Lab 3: Blackjack
Pavel Vinduska
netid pvindusk
student id 000697226
This program allows two players to play blackjack.
 */

#include "CardDeck.h"   // class definition for CardDeck used below
#include <iomanip>
#include <ctime> // So the cards are shuffled correctly

using namespace std;


void play(CardDeck& deck) {
    char hitOrStand;
    int playerScore = 0;
    int dealerScore = 0;
    int blackJack = 21;

    bool gameOver = false;
    while (!gameOver) {
        vector<int> playerHand;
        vector<int> dealerHand;

        // Deal two cards to the player
        playerHand.push_back(deck.deal());
        playerHand.push_back(deck.deal());

        // Deal two cards to the dealer
        dealerHand.push_back(deck.deal());
        dealerHand.push_back(deck.deal());

        int playerTotalHand = playerHand[0] + playerHand[1];
        int dealerTotalHand = dealerHand[0] + dealerHand[1];

        cout << "Player total hand: " << playerTotalHand << endl;
        cout << "Dealer total hand: " << dealerTotalHand << endl;

        // Dealer's turn to hit if necessary
        while (dealerTotalHand < 17) {
            int newCard = deck.deal();
            dealerHand.push_back(newCard);
            dealerTotalHand += newCard;

            cout << "Dealer draws: " << newCard << ". Dealer's total: " << dealerTotalHand << endl;

            if (dealerTotalHand > blackJack) {
                cout << "Dealer busted!" << endl;
                break;
            }
        }

        // Player's turn: hit or stand
        cout << "Player: Hit or Stand (Type 'h' or 's')? ";
        cin >> hitOrStand;

        while (hitOrStand == 'h') {
            cout << "Player chose to hit!" << endl;
            int newCard = deck.deal();  // Deal a new card to the player
            playerHand.push_back(newCard);
            playerTotalHand += newCard;

            cout << "Player draws: " << newCard << ". Player's total: " << playerTotalHand << endl;

            if (playerTotalHand > blackJack) {
                cout << "Player busted!" << endl;
                break;
            }

            cout << "Player: Hit or Stand (Type 'h' for hit or 's' for stand)? ";
            cin >> hitOrStand;
        }

        // Compare hands if no one busted
        if (playerTotalHand <= blackJack && dealerTotalHand <= blackJack) {
            if (dealerTotalHand > playerTotalHand) {
                cout << "Dealer won!" << endl;
            } else if (playerTotalHand > dealerTotalHand) {
                cout << "Player won!" << endl;
            } else {
                cout << "It's a tie!" << endl;
            }
        }

        // Ask if the player wants to play again
        char playAgain;
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'n') {
            gameOver = true;
        } else {
            deck.shuffle();  // Shuffle the deck for the next round
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
  cout<< endl;

  play(*deck);
  delete deck;

  
  
}