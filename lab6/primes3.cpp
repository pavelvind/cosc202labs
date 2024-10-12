#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;

// Global variables
vector<bool> isPrime;   
vector<int> primes;     


void findPrimes(int num)
{
  
    isPrime.resize(num + 1, true);
    isPrime[0] = isPrime[1] = false;  

    int limit = static_cast<int>(sqrt(num));


    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            for (long long j = static_cast<long long>(i) * i; j <= num; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Collect all prime numbers into the 'primes' vector
    for (int i = 2; i <= num; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);  // Store the prime number
        }
    }
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

    // Find the largest input number to set the sieve limit
    int largestInput = inputs[0];
    for (size_t i = 1; i < inputs.size(); ++i)
    {
        if (inputs[i] > largestInput)
        {
            largestInput = inputs[i];
        }
    }

    // Generate primes up to the largest input number
    findPrimes(largestInput);

    // Use binary_search to check if each input number is prime
    for (size_t i = 0; i < inputs.size(); ++i)
    {
        if (binary_search(primes.begin(), primes.end(), inputs[i]))
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