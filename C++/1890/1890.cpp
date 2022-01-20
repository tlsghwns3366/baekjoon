#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long nn[n][n];
    long long bb[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            bb[i][j] = 0;
        }
    }
    bb[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n - 1 && j == n - 1)
                break;
            if (bb[i][j] != 0)
            {
                if (nn[i][j] + j < n)
                {
                    bb[i][j + nn[i][j]] += bb[i][j];
                }
                if (nn[i][j] + i < n)
                {
                    bb[i + nn[i][j]][j] += bb[i][j];
                }
            }
        }
    }
    cout << bb[n - 1][n - 1];
}