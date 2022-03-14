#include <iostream>
#include <climits>
using namespace std;
int n, m, D;
int **nm;
int ans = 0;
bool *b;
void f(int a, int c)
{
    if (c == 3)
    {
        int temp[n + 1][m + 1];
        int anstemp = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                temp[i][j] = nm[i][j];
            }
        }
        while (true)
        {
            bool w = false;
            int mincount = 0;
            int minx[3];
            int miny[3];
            int minr[3];
            for (int i = 1; i <= m; i++)
            {
                if (b[i])
                {
                    minx[mincount] = 0;
                    miny[mincount] = m + 1;
                    minr[mincount] = INT_MAX;
                    for (int x = 1; x <= n; x++)
                    {
                        for (int y = 1; y <= m; y++)
                        {
                            if (temp[x][y])
                            {
                                int tempabs = abs((n + 1) - x) + abs(i - y);
                                if (minr[mincount] > tempabs)
                                {
                                    minr[mincount] = tempabs;
                                    minx[mincount] = x;
                                    miny[mincount] = y;
                                }
                                else if (minr[mincount] == tempabs && miny[mincount] > y)
                                {
                                    minr[mincount] = tempabs;
                                    minx[mincount] = x;
                                    miny[mincount] = y;
                                }
                            }
                        }
                    }
                    mincount++;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                if (D >= minr[i] && temp[minx[i]][miny[i]] == 1)
                {
                    temp[minx[i]][miny[i]] = 0;
                    anstemp++;
                }
            }
            for (int i = n; i >= 1; i--)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (temp[i][j] == 1)
                    {
                        w = true;
                        temp[i][j] = 0;
                        if (i + 1 <= n)
                            temp[i + 1][j] = 1;
                    }
                }
            }
            if (!w)
                break;
        }
        if (ans < anstemp)
            ans = anstemp;

        return;
    }
    for (int i = a; i <= m; i++)
    {
        if (!b[i])
        {
            b[i] = true;
            f(i, c + 1);
            b[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> D;
    nm = new int *[n + 1];
    b = new bool[m + 1];
    fill(b, b + m + 1, false);
    for (int i = 1; i <= n; i++)
    {
        nm[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            cin >> nm[i][j];
        }
    }
    f(1, 0);
    cout << ans;
}