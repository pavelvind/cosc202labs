#include <iostream>
#include <vector>

using namespace std;

void enumerate(vector<int> &v, int pos)
{
    if (pos == 8)
    {
        vector<bool> duplicate(8, false); // Initialize with 8 elements set to false
        bool hasDuplicate = false;

        for (int i = 0; i < 8; i++)
        {
            if (duplicate[v[i]])
            {
                cout << "Queens on the same row.\n";
                hasDuplicate = true;
                break; // No need to check further
            }
            else
            {
                duplicate[v[i]] = true;
            }
        }

        if (!hasDuplicate)
        {
            for (int i = 0; i < 8; i++)
            {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            v[pos] = i;
            enumerate(v, pos + 1);
        }
    }
}

int main()
{
    vector<int> nums(8, 0); // Initialize with size 8
    enumerate(nums, 0);
    return 0;
}