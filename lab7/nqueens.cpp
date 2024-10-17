// Lab 7:  N-queens using backtracking

#include <iostream>
#include <vector>

using namespace std;

// Recursive function
// Recursive call: Putting a new queen on the board and increment col
void nqueens(vector<int> &board, int col, int size)
{

  int row = board[col];
  // Recursive case
  if (col < size)
  {
    
      board[col] = row; // Place queen
      // Recursive call -> move in cols till i reach the boardsize
      nqueens(board, col + 1, size);
    
  }
  // Base case
  else if (col == size)
  {
    // Board is valid
    if(isValid){
      print(board);
    }
    // If false -> go back one recursion and start the board with the qlueen one spot lower
    else{
      row++;
      nqueens(board, col - 1, size);
    }
  }
}
// Proper nqueen board without duplicates in row cols diagonals
bool isValid(const vector<int> &board, int size, int col)
{
  // Row check
  vector<int> rowCount(size, 0);
  for (int i = 0; i < size; ++i)
  {
    if (board[i] != -1)
    {
      rowCount[board[i]]++;
    }
    if (rowCount[board[i]] > 1)
    {
      return false; // Duplicate row found
    }
  }

  // Diagonal check
  for(int i = 0; i < col; ++i)
    {
        if(abs(board[i] - board[col]) == abs(i - col))
            return false; // Diagonal conflict
    }
    
    return true;
}

void print(const vector<int> &board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    cout << board[i] << " ";
  }
}

int main(int argc, char *argv[])
{
  int size = 0;
  // Take the num from arguments
  if (argc > 1)
  {
    // Convert the first argument to an integer
    size = stoi(argv[1]);
  }
  else
  {
    cout << "Please provide a number as a commandline argument." << endl;
  }

  // Initialize board vector
  vector<int> board(size, -1);
  nqueens(board, 0, size);

  return 0;
}
