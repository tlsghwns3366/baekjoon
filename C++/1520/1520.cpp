#include <iostream>
using namespace std;
int n, m;
int nm[501][501];
int count[501][501];

void uprightdown(int a, int b, int c, int x)
{
    if (a - 1 >= 0)
    {
        if (nm[a - 1][b] < nm[a][b])
        {
            count[a - 1][b] += c;
            uprightdown(a - 1, b, c, x);
        }
    }
    if (a + 1 < x)
    {
        if (nm[a + 1][b] < nm[a][b])
        {
            count[a + 1][b] += c;
            uprightdown(a + 1, b, c, x);
        }
    }
    if (b + 1 < m)
    {
        if (nm[a][b + 1] < nm[a][b])
        {
            count[a][b + 1] += c;
            uprightdown(a, b + 1, c, x);
        }
    }
}
void upleftdown(int a, int b)
{
    if (a - 1 >= 0)
    {
        if (nm[a - 1][b] > nm[a][b])
            count[a][b] += count[a - 1][b];
    }
    if (b - 1 >= 0)
    {
        if (nm[a][b - 1] > nm[a][b])
            count[a][b] += count[a][b - 1];
    }
}
void upleftup(int a, int b)
{
    if (a - 1 >= 0)
    {
        if (nm[a - 1][b] < nm[a][b])
        {
            count[a - 1][b] += count[a][b];
            uprightdown(a - 1, b, count[a][b], a);
        }
    }
    if (b - 1 >= 0)
    {
        if (nm[a][b - 1] < nm[a][b])
            count[a][b - 1] += count[a][b];
    }
}
int main()
{
    cin >> n >> m;
    count[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
            upleftdown(i, j);
            upleftup(i, j);
        }
    }
    cout << count[n - 1][m - 1];
}