/*  
Lab 3: Blackjack
Pavel Vinduska
netid pvindusk
student id 000697226
This program allows two players to play blackjack.
 */

#include "CardDeck.h"   // Class definition for CardDeck used below
#include <iomanip>
#include <ctime> // So the cards are shuffled correctly


using namespace std;


void play(CardDeck& deck) {
    char hitOrStand;
    int playerScore = 0;
    int dealerScore = 0;
    int blackJack = 21;
    int playerWins = 0;  
     int dealerWins = 0;

    // Interactive loop
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

        // Calculate the hand totals 
        int playerTotalHand = playerHand[0] + playerHand[1];
        int dealerTotalHand = dealerHand[0] + dealerHand[1];

        cout << "Player total hand: " << playerTotalHand << endl;
        cout << "Dealer total hand: " << dealerTotalHand << endl;

        // Dealer's turn to hit 
        while (dealerTotalHand < 17) {
            int newCard = deck.deal();
            dealerHand.push_back(newCard);
            dealerTotalHand += newCard;

            cout << "Dealer draws: " << newCard << ". Dealer's total: " << dealerTotalHand << endl;

            if (dealerTotalHand > blackJack) {
                cout << "Dealer busted!" << endl;
                playerWins++;
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
                dealerWins++;
                break;
            }

            cout << "Player: Hit or Stand (Type 'h' for hit or 's' for stand)? ";
            cin >> hitOrStand;
        }

        // Compare hands if no one busted
        if (playerTotalHand <= blackJack && dealerTotalHand <= blackJack) {
            if (dealerTotalHand > playerTotalHand) {
                cout << "Dealer won!" << endl;
                dealerWins++;  // Increment dealer wins
            } else if (playerTotalHand > dealerTotalHand) {
                cout << "Player won!" << endl;
                playerWins++;  // Increment player wins
            } else {
                cout << "It's a tie!" << endl;
            }
        }

        // Display the total wins for both player and dealer
        cout << "Player Wins: " << playerWins << " | Dealer Wins: " << dealerWins << endl;

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
  deck = new CardDeck;  // Dynamically allocates memory for a CardDeck object and calls the CardDeck constructor to initialize the deck

  // Print carddeck ordered 
  cout << endl << "Printing ordered deck. " << endl;
  deck->print();  // Use '->' instead of '.' because 'deck' is a pointer to an object

  // Print shuffled deck 
  cout << endl << "Printing shuffled deck. " << endl;
  deck->shuffle();
  deck->print();
  cout<< endl;

  play(*deck);
  delete deck;

  
  
}