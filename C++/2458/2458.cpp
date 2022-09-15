#include <iostream>
using namespace std;
int n, m;
int nn[501][501];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nn[i][j] = 987654321;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        nn[a][b] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (nn[j][k] > nn[j][i] + nn[i][k])
                    nn[j][k] = nn[j][i] + nn[i][k];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (nn[i][j] != 987654321 || nn[j][i] != 987654321)
                temp++;
        }
        if (temp == n - 1)
            ans++;
    }
    cout << ans;
}