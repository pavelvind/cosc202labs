#include "CardDeck.h"

// Constructor implementation 
CardDeck::CardDeck() {
    size = 52; 
    for (int i = 0; i < size; i++) {
        deck[i] = i + 1;  
    }
}


void CardDeck::shuffle(){

}

