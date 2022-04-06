#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n;
    cin >> n;
    int nn[n][n];
    bool bn[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 1)
                bn[i][j] = true;
            else
                bn[i][j] = false;
        }
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bn[i][j] == true)
            {
                queue<pair<int, int>> q;
                bn[i][j] = false;
                nn[i][j] = count;
                q.push({i, j});
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < n)
                        {
                            if (bn[x + dx[k]][y + dy[k]] == true)
                            {
                                bn[x + dx[k]][y + dy[k]] = false;
                                nn[x + dx[k]][y + dy[k]] = count;
                                q.push({x + dx[k], y + dy[k]});
                            }
                        }
                    }
                }
                count++;
            }
        }
    }

    int ans = 987654321;
    for (int w = 1; w < count; w++)
    {
        queue<pair<pair<int, int>, int>> q;
        fill(&bn[0][0], &bn[n - 1][n], false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nn[i][j] == w)
                {
                    q.push({{i, j}, 0});
                    bn[i][j] = true;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int c = q.front().second;
            q.pop();
            if (nn[x][y] != 0 && nn[x][y] != w)
            {
                ans = ans > c - 1 ? c - 1 : ans;
                break;
            }
            for (int k = 0; k < 4; k++)
            {
                if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < n)
                {
                    if (nn[x + dx[k]][y + dy[k]] != w && !bn[x + dx[k]][y + dy[k]])
                    {
                        q.push({{x + dx[k], y + dy[k]}, c + 1});
                        bn[x + dx[k]][y + dy[k]] = true;
                    }
                }
            }
        }
    }
    cout << ans;
}