/*
Lab 6: Is it prime?
Pavel Vinduska
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
using namespace std;

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
            for (long long j = i * i; j <= num; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Print the primes, 20 per line
    for (int i = 2; i <= num; ++i)
    {
        if (isPrime[i])
        {
            cout << setw(6) << i;
            primeCount++;

            if (primeCount % 20 == 0)
            {
                cout << endl;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        // Convert the first argument to an integer
        int num = stoi(argv[1]);

        // Call findPrimes with the arg val
        findPrimes(num);
    }
    else
    {
        cout << "Please provide a number as a commandline argument." << endl;
    }
    return 0;
}