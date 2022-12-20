#include <iostream>
#include <queue>
using namespace std;
int nm[101][101];
int ch[101][101];
bool b[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }
    int ans = 0;
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ch[i][j] = 0;
                b[i][j] = 0;
            }
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        b[0][0] = true;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0)
                {
                    if (b[x + dx[i]][y + dy[i]])
                        continue;
                    if (nm[x + dx[i]][y + dy[i]] == 1)
                    {
                        ch[x + dx[i]][y + dy[i]]++;
                    }
                    else
                    {
                        b[x + dx[i]][y + dy[i]] = true;
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
        bool bans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ch[i][j] >= 2)
                {
                    nm[i][j] = 0;
                    bans = true;
                }
            }
        }
        if (bans)
            ans++;
        else
            break;
    }
    cout << ans;
}