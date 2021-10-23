#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int **nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nn[j][i] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (nn[i][k] == 1)
                    {
                        nn[j][k] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nn[i][j] << " ";
        }
        cout << endl;
    }
}