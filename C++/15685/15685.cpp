#include <iostream>
using namespace std;
int nn[101][101];
int g[11][1025];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    int n;
    cin >> n;
    fill(&g[0][0], &g[10][1025], -1);
    g[0][0] = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 1025; j++)
        {
            if (g[i][j] == -1)
            {
                for (int z = 1; z <= j; z++)
                {
                    if (g[i][j - z] == 3)
                        g[i + 1][j + z - 1] = 0;
                    else
                        g[i + 1][j + z - 1] = g[i][j - z] + 1;
                }
                break;
            }
            else
            {
                g[i + 1][j] = g[i][j];
            }
        }
    }
    for (int q = 0; q < n; q++)
    {
        int x, y, d, ig;
        cin >> x >> y >> d >> ig;
        nn[y][x] = 1;
        for (int i = 0; i < 1025; i++)
        {
            if (g[ig][i] == -1)
                break;
            else
            {
                int temp = (g[ig][i] + d) % 4;
                x += dx[temp];
                y += dy[temp];
                nn[y][x] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (nn[i][j] == 1 && nn[i][j + 1] == 1 && nn[i + 1][j] == 1 && nn[i + 1][j + 1] == 1)
                ans++;
        }
    }
    cout << ans;
}