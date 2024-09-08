#include "C4Board.h"
#include "C4Col.h"
using namespace std;

C4Board::C4Board() {
    // the constructor initializes an array of C4Col objects
    for (int i = 0; i < numCols; i++) {
        c4colArray[i] = C4Col();
    }
}

void C4Board::play() {

// creates the interactive loop (similat to lab 1)
//differences are in error checks

/*
1 prompt the corrrect player 
2 read and error check the move
3 update and print the board
4 winner or tie? (check_winner function)
*/

 // loop to ask for input and change turns
    int turn = 0;
    while(!gameOver){
    
        
        char player;
        

        // prompt the corrrect player 
        if ((turn % 2) == 0) {
            cout <<endl << "It is X's turn, col: (number between 0-6)" << endl;
            player = 'X';
        } else {
            cout << endl <<"It is O's turn, enter col: (number between 0-6)" << endl;
            player = 'O';
        }
        turn++;
        // read and error check the move
        cin >> col;
        while (col < 0 || col >= numCols || c4colArray[col].isFull()) {
            cout << "Invalid move. Try again: ";
            cin >> col;
        }
        
        // addDisc
        c4colArray[col].addDisc(player);

        // update and print the board
        display();

        // winner or tie? (check_winner function)
        getDiscPosition(row, col); //where the disc was just placed

        // horizontal check
        xStreak = 0;
        oStreak = 0;
        for(int i = 0; i < numCols; i++){
            char disc = c4colArray[i].getDisc(row);
            // X
            if (disc == 'X') {
                xStreak++;  
                oStreak = 0;  
        if (xStreak == connected) {  
                gameOver = true;
            cout << "Player X wins!" << endl;
            break;  // break out once the game is over
        }
    }
    // O
    else if (disc == 'O') {
        oStreak++;  
        xStreak = 0;  
        if (oStreak == connected) {  
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;  
        }
    } 
    // ' '
    else {
        // reset
        xStreak = 0;
        oStreak = 0;
    }
}




// vertical check 
xStreak = 0;
oStreak = 0;
for (int i = 0; i < numRows; i++) {  
    char disc = c4colArray[col].getDisc(i); 
    
    // X
    if (disc == 'X') {
        xStreak++;  
        oStreak = 0;  
        if (xStreak == connected) {  
            gameOver = true;
            cout << "Player X wins!" << endl;
            break;  
        }
    } 
    // O
    else if (disc == 'O') {
        oStreak++;  
        xStreak = 0;  
        if (oStreak == connected) {  
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;  
        }
    } 
    // ' ' 
    else {
        //r eset
        xStreak = 0;
        oStreak = 0;
    }
}

// diagonal check
// bottom-left to top-right diagonal (ascending)
xStreak = 0;
oStreak = 0;

// check diagonally upwards and right (bottom-left to top-right)
int r = row, c = col;
while (r >= 0 && c >= 0) {
    char disc = c4colArray[c].getDisc(r);
    // X
    if (disc == 'X') {
        xStreak++;
        oStreak = 0;
        if (xStreak == connected) {
            gameOver = true;
            cout << "Player X wins!" << endl;
            break;
        }
    } 
    // O
    else if (disc == 'O') {
        oStreak++;
        xStreak = 0;
        if (oStreak == connected) {
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;
        }
    } 
    // ' '
    else {
        xStreak = 0;
        oStreak = 0;
    }
    r--;  // move upwards (row decreases)
    c++;  // move right (column increases)
}

// check diagonally downwards and left (top-right to bottom-left)
r = row, c = col;
while (r < numRows && c >= 0) {
    char disc = c4colArray[c].getDisc(r);
    // X
    if (disc == 'X') {
        xStreak++;
        oStreak = 0;
        if (xStreak == connected) {
            gameOver = true;
            cout << "Player X wins!" << endl;
            break;
        }
    } 
    // O
    else if (disc == 'O') {
        oStreak++;
        xStreak = 0;
        if (oStreak == connected) {
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;
        }
    } 
    // ' '
    else {
        xStreak = 0;
        oStreak = 0;
    }
    r++;  // move downwards (row increases)
    c--;  // move left (column decreases)
}

// top-left to bottom-right diagonal (descending)
xStreak = 0;
oStreak = 0;

// check diagonally downwards and right (top-left to bottom-right)
r = row, c = col;
while (r < numRows && c < numCols) {
    char disc = c4colArray[c].getDisc(r);
    // X
    if (disc == 'X') {
        xStreak++;
        oStreak = 0;
        if (xStreak == connected) {
            gameOver = true;
            cout << "Player X wins!" << endl;
            break;
        }
    } 
    // O
    else if (disc == 'O') {
        oStreak++;
        xStreak = 0;
        if (oStreak == connected) {
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;
        }
    } 
    // ' '
    else {
        xStreak = 0;
        oStreak = 0;
    }
    r++;  // move downwards (row increases)
    c++;  // move right (column increases)
}

// check diagonally upwards and left (bottom-right to top-left)
r = row, c = col;
while (r >= 0 && c >= 0) {
    char disc = c4colArray[c].getDisc(r);
   // X
   if (disc == 'X') {
        xStreak++;
        oStreak = 0;
        if (xStreak == connected) {
            gameOver = true;
            cout << "Player X wins!" << endl;
            break;
        }
    } 
    // O
    else if (disc == 'O') {
        oStreak++;
        xStreak = 0;
        if (oStreak == connected) {
            gameOver = true;
            cout << "Player O wins!" << endl;
            break;
        }
    } 
    // ' '
    else {
        xStreak = 0;
        oStreak = 0;
    }
    r--;  // move upwards (row decreases)
    c--;  // move left (column decreases)
}


// exit the loop if gameOver is true
if (gameOver) return;

    }
        

}


void C4Board::display() {
    // display the column numbers
    cout << "  ";
    for (int j = 0; j < numCols; j++) {
        cout << "  " << j << " ";  
    }
    cout << endl;

    
    for (int i = numRows - 1; i >= 0; i--) {
        cout << " ";  
        
        
        for (int j = 0; j < numCols; j++) {
            cout << "| " << c4colArray[j].getDisc(i) << " ";  
        }
        cout << "|" << endl;  

        
        cout << "  ";
        for (int j = 0; j < numCols; j++) {
            cout << "----";  
        }
        cout << "-" << endl;  
    }
    cout << endl;
}
// disc position -> implemented in winner-checking
void C4Board::getDiscPosition(int &row, int &col) {
    
    row = c4colArray[col].getNumDiscs() - 1; 
}