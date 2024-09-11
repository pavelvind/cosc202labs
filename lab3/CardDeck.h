#ifndef CARDDECK_H 
#define CARDDECK_H 

#include <iostream>
#include <algorithm>
using namespace std;

class CardDeck {

private:
    int size;
    int* deck; //updated member function to use dynamic memory

public:

    void shuffle();
    void print();
    int getSize();

    CardDeck();                 // default construcor
    CardDeck(const CardDeck &); // copy constructor
    ~CardDeck();                // destructor

    const CardDeck& operator=(const CardDeck& ); // assignment operator

};

#endif