#include <iostream>
using namespace std;

int wabc[21][21][21] = {0};

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (a < b && b < c)
    {
        return wabc[a][b][c - 1] + wabc[a][b - 1][c - 1] - wabc[a][b - 1][c];
    }
    else
    {
        return wabc[a - 1][b][c] + wabc[a - 1][b - 1][c] + wabc[a - 1][b][c - 1] - wabc[a - 1][b - 1][c - 1];
    }
}

int main()
{
    int a, b, c;
    int *dfs = new int[10];
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            for (int k = 0; k <= 20; k++)
            {
                wabc[i][j][k] = w(i, j, k);
            }
        }
    }
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        else
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
            }
            else if (a > 20 || b > 20 || c > 20)
            {
                printf("w(%d, %d, %d) = %d\n", a, b, c, wabc[20][20][20]);
            }
            else
            {
                printf("w(%d, %d, %d) = %d\n", a, b, c, wabc[a][b][c]);
            }
        }
    }
}