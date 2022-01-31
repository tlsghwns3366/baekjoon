#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int nn[6];
    for (int i = 1; i < 6; i++)
    {
        cin >> nn[i];
    }
    for (int k = 5; k >= 1; k--)
    {
        for (int j = 1; j < k; j++)
        {
            if (nn[j] > nn[j + 1])
            {
                swap(nn[j], nn[j + 1]);
                for (int i = 1; i < 6; i++)
                {
                    cout << nn[i] << " ";
                }
                cout << "\n";
            }
        }
    }
}