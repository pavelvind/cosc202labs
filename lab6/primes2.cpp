/* Lab 6: Is it prime?
https://www.geeksforgeeks.org/std-find-in-cpp/
https://www.geeksforgeeks.org/how-to-find-last-element-in-a-set-in-cpp/
*/

#include <set>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Global
set<int> s1;

// Sieve of Eratosthenes
void findPrimes(int num)
{
  vector<bool> isPrime(num + 1, true);
  int limit = sqrt(num);

  for (int i = 2; i <= limit; ++i)
  {
    if (isPrime[i])
    {
      // Mark multiples of 'i' as non-prime
      for (long long j = i * i; j <= num; j += i)
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
  // int largestPrime = *s1.rbegin();
  // return largestPrime;
}

int main()
{

  /// Vector to store all input numbers
  vector<int> inputs;
  int num;

  // Read all inputs into the vector
  while (cin >> num)
  {
    inputs.push_back(num);
  }

  if (inputs.empty())
  {
    cerr << "No input numbers provided." << endl;
    return 1;
  }

  // Find the largest input number
  int largestInput = inputs[0];
  for (size_t i = 1; i < inputs.size(); ++i)
  {
    if (inputs[i] > largestInput)
    {
      largestInput = inputs[i];
    }
  }

  // Generate primes till the largest input
  findPrimes(largestInput);

  for (size_t i = 0; i < inputs.size(); ++i)
  {

    // Find in the set for the prime
    if (s1.find(inputs[i]) != s1.end())
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