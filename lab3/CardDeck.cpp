#include "CardDeck.h"


// Default constructor
CardDeck::CardDeck() {
    size = 52;

    deck = new int[size];

    for (int i = 0; i < size; i++) {
        deck[i] = i + 1;  
    }
    
}

// Copy construcor
// Ensures that the two CardDeck objects do not share the same memory
CardDeck::CardDeck(const CardDeck &CardDeckToCopy) {
    // Copy the size first
    size = CardDeckToCopy.size;

    // Allocate new memory for the deck array
    deck = new int[size];

    // Copy each element from the original deck to the new one (deep copy)
    for (int i = 0; i < size; i++) {
        deck[i] = CardDeckToCopy.deck[i];
    }
}

// Deconstrucor
CardDeck::~CardDeck(){
    delete [] deck;
}

// Assignment operator
CardDeck& CardDeck::operator=(const CardDeck &CardDeckToCopy) {

    // Check for self-assignment
    if (this != &CardDeckToCopy) {
        // Free existing memory to avoid memory leaks
        delete[] deck;

        // Copy the size
        size = CardDeckToCopy.size;

        // Allocate new memory for the deck array
        deck = new int[size];

        // Copy each element from the original deck to the new one (deep copy)
        for (int i = 0; i < size; i++) {
            deck[i] = CardDeckToCopy.deck[i];
        }
    }

    // Return the current object (this) to allow chaining
    return *this;
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

