//lab1 toecheck 
//Pavel Vinduska
//netid pvindusk
//student id 000697226
//this program determines the winner after each turn and displays the board.
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    int size = 0; //how big is the grid
    int xStreak = 0;
    int oStreak = 0;

    //read the grid size
    cin >> size;
    cin.ignore();
    vector<vector<char>> grid(size, vector<char>(size));

    //load the data into 2D grid
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> grid[i][j];
        }
    }

    //horizontal check
    for(int i = 0; i < size; i++){
        xStreak = 0;
        oStreak = 0;
        for(int j = 0; j < size; j++){
            if(grid[i][j] == 'X') xStreak++;
            if(grid[i][j] == 'O') oStreak++;
        }
        if(xStreak == size){ 
            cout << "X wins" << endl; 
            return 0;
        }
        if(oStreak == size){ 
            cout << "O wins" << endl; 
            return 0;
        }
    }

    //vertical check
    for(int j = 0; j < size; j++){
        xStreak = 0;
        oStreak = 0;
        for(int i = 0; i < size; i++){
            if(grid[i][j] == 'X') xStreak++;
            if(grid[i][j] == 'O') oStreak++;
        }
        if(xStreak == size){ 
            cout << "X wins" << endl; 
            return 0;
        }
        if(oStreak == size){ 
            cout << "O wins" << endl; 
            return 0;
        }
    }

    //diagonal check top
    xStreak = 0;
    oStreak = 0;
    for(int i = 0; i < size; i++){
        if(grid[i][i] == 'X') xStreak++;
        if(grid[i][i] == 'O') oStreak++;
    }
    if(xStreak == size){ 
        cout << "X wins" << endl; 
        return 0;
    }
    if(oStreak == size){ 
        cout << "O wins" << endl; 
        return 0;
    }

    //diagonal check bottom
    xStreak = 0;
    oStreak = 0;
    for(int i = 0; i < size; i++){
        if(grid[size - 1 - i][i] == 'X') xStreak++;
        if(grid[size - 1 - i][i] == 'O') oStreak++;
    }
    if(xStreak == size){ 
        cout << "X wins" << endl; 
        return 0;
    }
    if(oStreak == size){ 
        cout << "O wins" << endl; 
        return 0;
    }

    //tie
    cout << "Tie" << endl;
    return 0;
}