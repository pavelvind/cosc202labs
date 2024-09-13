#ifndef CARDDECK_H 
#define CARDDECK_H 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CardDeck {
public:

    void shuffle();
    void print();
    int deal();
    int getSize();
    int play();

    CardDeck(int n = 52);             // Non default Parameter con
    CardDeck(const CardDeck &); // Copy constructor
    ~CardDeck();               // Destructor

    CardDeck& operator=(const CardDeck &CardDeckToCopy); // Assignment operator

private:
    int size;
    int* deck;       // Updated member function to use dynamic memory
    int index = 52; // Keeps track of what place are we in deck (deal function)
    static const char card_faces[13];  
    static const int card_values[13];
    int playerScore;
    int dealerScore;
    vector<int> playerHand;
    vector<int> dealerHand;
    bool gamOver;


};

#endif