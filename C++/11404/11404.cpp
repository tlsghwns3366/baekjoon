#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int d[n + 1][n + 1];
    fill(&d[0][0], &d[n][n + 1], 987654321);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[a][b] > c ? c : d[a][b];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (d[j][k] > d[j][i] + d[i][k])
                    d[j][k] = d[j][k] < d[j][i] + d[i][k] ? d[j][k] : d[j][i] + d[i][k];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == 987654321)
                cout << "0 ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}