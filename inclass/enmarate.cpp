#include <iostream>
#include <vector>

using namespace std;

void enumerate(vector<int> v, int pos)
{

    if (pos == 8)
    {
        vector<bool> duplicate;
        duplicate.resize(10);

        for (int i = 0; i < 8; i++)
        {
            if (duplicate[v[i] == true])
            {
                cout << "Queen on same row";
            }
            else
            {
                duplicate[v[i] == true];
            }
            cout << v[i] << "  ";
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
    vector<int> nums;
    int pos = 0;
}