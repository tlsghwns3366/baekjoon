#include <iostream>
using namespace std;
int main()
{
    int n, m1;
    cin >> n >> m1;
    int nm1[n][m1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> nm1[i][j];
        }
    }
    int m2, k;
    cin >> m2 >> k;
    int m2k[m2][k];
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> m2k[i][j];
        }
    }
    int nk[n][k];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int a = 0;
            nk[i][j] = 0;
            while (a < m1)
            {
                nk[i][j] += nm1[i][a] * m2k[a][j];
                a++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << nk[i][j] << " ";
        }
        cout << endl;
    }
}