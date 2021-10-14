#include <iostream>
#include <climits>
using namespace std;
int n, m;
void f(int **nn, int **bb, int a, int b)
{
    if (a == n && b == m)
        return;
    else
    {
        if (a - 1 >= 0 && nn[a][b] != 0)
        {
            if (bb[a - 1][b] > bb[a][b] + 1)
            {
                bb[a - 1][b] = bb[a][b] + 1;
                f(nn, bb, a - 1, b);
            }
        }
        if (a + 1 < n && nn[a][b] != 0)
        {
            if (bb[a + 1][b] > bb[a][b] + 1)
            {
                bb[a + 1][b] = bb[a][b] + 1;
                f(nn, bb, a + 1, b);
            }
        }
        if (b - 1 >= 0 && nn[a][b] != 0)
        {
            if (bb[a][b - 1] > bb[a][b] + 1)
            {
                bb[a][b - 1] = bb[a][b] + 1;
                f(nn, bb, a, b - 1);
            }
        }
        if (b + 1 < m && nn[a][b] != 0)
        {
            if (bb[a][b + 1] > bb[a][b] + 1)
            {
                bb[a][b + 1] = bb[a][b] + 1;
                f(nn, bb, a, b + 1);
            }
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    int **nn = new int *[n];
    int **bb = new int *[n];
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        nn[i] = new int[m];
        bb[i] = new int[m];
        for (int j = 0; j < a.length(); j++)
        {
            nn[i][j] = a[j] - '0';
            bb[i][j] = INT_MAX;
        }
    }
    bb[0][0] = 1;
    f(nn, bb, 0, 0);
    cout << bb[n - 1][m - 1];
}