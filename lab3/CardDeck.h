#ifndef CARDDECK_H 
#define CARDDECK_H 

#include <iostream>

class CardDeck {

private:
    int size;
    int deck[52];

public:

    void shuffle();
    int getSize();

    CardDeck();                 // default construcor
    CardDeck(const CardDeck &); // copy constructor
    ~CardDeck();                // destructor

    const CardDeck& operator=(const CardDeck& ); // assignment operator

};

#endif