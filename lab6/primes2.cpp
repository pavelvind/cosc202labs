/* Lab 6: Is it prime?
https://www.geeksforgeeks.org/std-find-in-cpp/
https://www.geeksforgeeks.org/how-to-find-last-element-in-a-set-in-cpp/
*/

#include <set>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

// Global
set<int> s1;

// Sieve of Eratosthenes
void findPrimes(int num)
{
  int primeCount = 0;
  vector<bool> isPrime(num + 1, true);
  int limit = sqrt(num);

  for (int i = 2; i <= limit; ++i)
  {
    if (isPrime[i])
    {
      // Mark multiples of 'i' as non-prime
      for (int j = i * i; j <= num; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  // Store the primes into set
  for (int i = 2; i <= num; ++i)
  {
    if (isPrime[i])
    {
      s1.insert(i);
    }
  }
}

void extendPrimes(int newNum)
{
}

int main(int argc, char *argv[])
{
  findPrimes(10000000);
  int num;
  set<int> s2;

  // Find in the set for the prime
  while (cin >> num)
  {
    
      // Store the input in set
      //s2.insert(num);

      // Dereference largest input
      // int largestInput = *s2.rbegin();

      // Check if the largest # in the inputs is bigger than the largest prime in the set
      int largestPrime = *s1.rbegin(); // Dereferenced reversed iterator (Time complexity: O(1))
      

      if (s1.find(num) != s1.end())
      {
        cout << "prime" << endl;
      }
      else
      {
        cout << "not prime" << endl;
      }
    }
  

  return 0;
}