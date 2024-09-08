// Lab 1:  Tic-tac-toe solver
//Pavel Vinduska
//netid pvindusk
//student id 000697226
//This program allows two players to play Tic-tac-toe on a board of size n x n.
//It determines the winner after each turn and displays the board.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace  std;

//implemented toechcek function
 int ToeCheck(const vector<vector<char>>& grid, int size) {
    int xStreak, oStreak;

    //horizontal check
    for (int i = 0; i < size; i++) {
        xStreak = 0;
        oStreak = 0;
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 'X') xStreak++;
            if (grid[i][j] == 'O') oStreak++;
        }
        if (xStreak == size) return 1; 
        if (oStreak == size) return 2; 
    }

    //vertical check
    for (int j = 0; j < size; j++) {
        xStreak = 0;
        oStreak = 0;
        for (int i = 0; i < size; i++) {
            if (grid[i][j] == 'X') xStreak++;
            if (grid[i][j] == 'O') oStreak++;
        }
        if (xStreak == size) return 1; 
        if (oStreak == size) return 2; 
    }

    //diagonal check top
    xStreak = 0;
    oStreak = 0;
    for (int i = 0; i < size; i++) {
        if (grid[i][i] == 'X') xStreak++;
        if (grid[i][i] == 'O') oStreak++;
    }
    if (xStreak == size) return 1; 
    if (oStreak == size) return 2; 

    //diagonal check top bottom
    xStreak = 0;
    oStreak = 0;
    for (int i = 0; i < size; i++) {
        if (grid[i][size - 1 - i] == 'X') xStreak++;
        if (grid[i][size - 1 - i] == 'O') oStreak++;
    }
    if (xStreak == size) return 1; 
    if (oStreak == size) return 2; 

    //check for a tie
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == '-') return -1; 
        }
    }
return 0;
}


int main(int argc, char *argv[]) {
  //read the grid size
  int size;
  cout << "choose grid size" << endl;
  cin >> size;
  char sign;
  
  vector<vector<char>> grid(size, vector<char>(size, '-'));

  //show grid
  for(int i = 0; i < size; i++){
        cout << endl;
        for(int j = 0; j < size; j++){
            cout << "-" << " ";
        }
        
    }

  //loop to ask for input and change turns
    for (int i = 0; i < size * size; i++) {
        int row, col;
        char player;

        if ((i % 2) == 0) {
            cout <<endl << "It is X's turn, enter row and col: " << endl;
            player = 'X';
        } else {
            cout << endl <<"It is O's turn, enter row and col: " << endl;
            player = 'O';
        }

        cin >> row >> col;
        row --;
        col --;

        //check input
        if ((row >= 0) && (row < size) && (col >= 0) && (col < size) && (grid[row][col] == '-')) {
            grid[row][col] = player;
        } else {
            cout << "Invalid move, try again." << endl;
            i--;
            continue;
        }

        //show grid
        for (int i = 0; i < size; i++) {
            cout << endl;
            for (int j = 0; j < size; j++) {
                cout << grid[i][j] << " ";
            }

        }
        cout << endl;
        //check for a win or tie
        int result = ToeCheck(grid, size);
        if (result != -1) {
            if (result == 0) cout << "Tie" << endl;
            else {if (result == 1) {
            cout << "X wins" << endl;
            } else if (result == 2) {
            cout << "O wins" << endl;
}}
            break;
        }
    
    }

}