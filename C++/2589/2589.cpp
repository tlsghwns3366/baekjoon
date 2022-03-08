#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;

    char nm[n][m];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            nm[i][j] = temp[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nm[i][j] == 'L')
            {
                int bb[n][m];
                for (int x = 0; x < n; x++)
                {
                    for (int y = 0; y < m; y++)
                    {
                        if (nm[x][y] == 'L')
                            bb[x][y] = 0;
                        else
                            bb[x][y] = -1;
                    }
                }
                queue<pair<int, int>> q;
                q.push({i, j});
                bb[i][j] = 1;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int a = 0; a < 4; a++)
                    {
                        if (x + dx[a] < n && x + dx[a] >= 0 && y + dy[a] < m && y + dy[a] >= 0)
                        {
                            if (bb[x + dx[a]][y + dy[a]] == 0)
                            {
                                bb[x + dx[a]][y + dy[a]] = bb[x][y] + 1;
                                q.push({x + dx[a], y + dy[a]});
                                if (ans < bb[x + dx[a]][y + dy[a]])
                                    ans = bb[x + dx[a]][y + dy[a]];
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans - 1;
}