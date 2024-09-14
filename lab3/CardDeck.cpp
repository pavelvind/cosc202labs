#include "CardDeck.h"

//const char CardDeck::card_faces[13] = {'2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};
const int CardDeck::card_values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

// Default constructor
CardDeck::CardDeck(int n) {
    
    size = n;

    deck = new int[size];

    for (int i = 0; i < size; i++) {
        deck[i] = i + 1;  
    }
    index = size-1;
    
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
    cout << "Destrucor called." << endl;
}

// Assignment operator
CardDeck& CardDeck::operator=(const CardDeck &CardDeckToCopy) {

    // Check for self-assignment
    if (this != &CardDeckToCopy) { // This refers to the object on the left
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
    for (int i = 0; i < 10; i++){
        cout << deck[i] << " ";
    }
    cout << endl;
}

void CardDeck::shuffle(){

    srand(time(0)); 
    random_shuffle(deck, deck + size);  // Shuffle the deck array
}

int CardDeck::getSize() {
    return size;
}


// Return the card value
int CardDeck::deal() {
    if (index <= 15) {
        cout << "Fewer than 15 cards left. Creating a new deck and shuffling.." << endl;

        CardDeck newDeck(size);  // Create a new deck with the same size
        newDeck.shuffle();  // Shuffle the new deck
        
        *this = newDeck;  // Use the assignment operator to copy the new deck to the current object
        index = size - 1;        // Reset 
    }

    int cardIndex = deck[index] % 13;  // Get the card index 
    index--;
    
    return card_values[cardIndex];     
}

    