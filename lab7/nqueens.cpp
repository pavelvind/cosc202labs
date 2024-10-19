// Lab 7:  N-queens using backtracking

#include <iostream>
#include <vector>

using namespace std;

// Recursive function
// Recursive call: Putting a new queen on the board and increment col
// Proper nqueen board without duplicates in row cols diagonals
bool isValid(const vector<int> &board, int size, int col)
{
  // Check for conflicts between all pairs of queens
  for (int i = 0; i < size; ++i)
  {
    for (int j = i + 1; j < size; ++j)
    {
      // Check if queens are in the same row
      if (board[i] == board[j])
        return false;

      // Check if queens are in the same diagonal
      if (abs(board[i] - board[j]) == abs(i - j))
        return false;
    }
  }
  return true; // No conflicts
}

void print(const vector<int> &board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    cout << board[i] << " ";
  }
  cout << endl;
}
void nqueens(vector<int> &board, int col, int size)
{
  // Base case => All queens are placed
  if (col == size)
  {
    // Board is valid
    if (isValid(board, size, col) == true)
    {
      print(board);
    }
    return;


  }
  // Recursive case

  for (int row = 0; row < size; ++row)
  {
    board[col] = row; // Place queen at row col
    // Recursive call -> move in cols till i reach the boardsize
    nqueens(board, col + 1, size);
    // Bsvktrack
    board[col] = -1;
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
