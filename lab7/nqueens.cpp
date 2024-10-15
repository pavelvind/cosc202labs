// Lab 7:  N-queens using backtracking
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

  if (argc > 1)
  {
    // Convert the first argument to an integer
    int boardSize = stoi(argv[1]);
  }
  else
  {
    cout << "Please provide a number as a commandline argument." << endl;
  }

  return 0;
}
