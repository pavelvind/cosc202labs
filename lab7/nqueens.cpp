// Lab 7:  N-queens using backtracking

#include <iostream>
#include <vector>

using namespace std;

// Recursive function
// Recursive call: Putting a new queen on the board and increment col
void nqueens(vector<int> &board, int col, int size)
{

  if (col < size)
  {
  }
}
bool isValid(const vector<int> &board, int size)
{
  vector<bool> duplicate;
  duplicate.resize(size);

  for (int i = 0; i < size; ++i)
  {
  }
}

void print(const vector<int> &board)
{
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

  return 0;
}
