#include "CardDeck.h"


// Default constructor
CardDeck::CardDeck() {
    size = 52; 
    for (int i = 0; i < size; i++) {
        deck[i] = i + 1;  
    }
}

// Copy construcor
CardDeck::CardDeck(const CardDeck &){

}

// Deconstrucor
CardDeck::~CardDeck(){
    delete [] deck;
}

// Assignment operator
const CardDeck &operator=(const CardDeck & ){

}

void CardDeck::print(){
    size = 52; 
    for (int i = 0; i < size; i++){
        cout << deck[i] << " ";
    }
    cout << endl;
}

void CardDeck::shuffle(){
    random_shuffle(deck, deck + size);  // Shuffle the deck array
}

