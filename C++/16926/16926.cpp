#include <iostream>
using namespace std;
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    int nm[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }
    int c = (n < m ? n : m) / 2;
    for (int w = 0; w < r; w++)
    {
        for (int q = 0; q < c; q++)
        {
            int x = q;
            int y = q;
            int temp = nm[q][q];
            while (x < n - 1 - q)
            {
                int temp2 = nm[x + 1][y];
                nm[x + 1][y] = temp;
                temp = temp2;
                x++;
            }
            while (y < m - 1 - q)
            {
                int temp2 = nm[x][y + 1];
                nm[x][y + 1] = temp;
                temp = temp2;
                y++;
            }
            while (x >= 1 + q)
            {
                int temp2 = nm[x - 1][y];
                nm[x - 1][y] = temp;
                temp = temp2;
                x--;
            }
            while (y >= 1 + q)
            {
                int temp2 = nm[x][y - 1];
                nm[x][y - 1] = temp;
                temp = temp2;
                y--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << nm[i][j] << " ";
        }
        cout << "\n";
    }
}