#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

map<int, bool> primeMap;

void findPrimes(int num)
{
    vector<bool> isPrime(num + 1, true);
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

    for (int i = 2; i <= num; ++i)
    {
        if (isPrime[i])
        {
            primeMap[i] = true;
        }
    }
}

int main()
{
    vector<int> inputs;
    int num;

    while (cin >> num)
    {
        inputs.push_back(num);
    }

    if (inputs.empty())
    {
        cerr << "No input numbers provided." << endl;
        return 1;
    }

    int largestInput = inputs[0];
    for (size_t i = 1; i < inputs.size(); ++i)
    {
        if (inputs[i] > largestInput)
        {
            largestInput = inputs[i];
        }
    }

    findPrimes(largestInput);

    for (size_t i = 0; i < inputs.size(); ++i)
    {
        if (primeMap.find(inputs[i]) != primeMap.end() && primeMap[inputs[i]])
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