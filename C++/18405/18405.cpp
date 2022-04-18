#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n, k;
    cin >> n >> k;
    int nn[n][n];
    int time[n][n];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] != 0)
            {
                q.push({i, j});
                time[i][j] = 0;
            }
            else
                time[i][j] = 20000;
        }
    }
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = a + dx[i];
            int y = b + dy[i];
            if (x < n && x >= 0 && y < n && y >= 0)
            {
                if (time[x][y] >= time[a][b] + 1 && (nn[x][y] > nn[a][b] || nn[x][y] == 0))
                {
                    q.push({x, y});
                    time[x][y] = time[a][b] + 1;
                    nn[x][y] = nn[a][b];
                }
            }
        }
    }
    int s, ansx, ansy;
    cin >> s >> ansx >> ansy;
    if (time[ansx - 1][ansy - 1] <= s)
        cout << nn[ansx - 1][ansy - 1];
    else
        cout << 0;
}