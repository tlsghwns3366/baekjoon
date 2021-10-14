#include <iostream>
using namespace std;
int n, m;
void f(int **nn, int a, int b)
{
    if (nn[a][b] == 0)
        return;
    else
    {
        nn[a][b] = 0;
        if (a - 1 >= 0)
            f(nn, a - 1, b);
        if (a + 1 < m)
            f(nn, a + 1, b);
        if (b - 1 >= 0)
            f(nn, a, b - 1);
        if (b + 1 < n)
            f(nn, a, b + 1);
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> m >> n >> k;
        int **mn = new int *[m];
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            mn[j] = new int[n];
            fill(mn[j], mn[j] + n, 0);
        }
        for (int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            mn[a][b] = 1;
        }

        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (mn[j][k] == 1)
                {
                    count++;
                    f(mn, j, k);
                }
            }
        }
        cout << count << "\n";
    }
}