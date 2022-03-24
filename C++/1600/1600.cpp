#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int dx[12] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
int main()
{
    int k, w, h;
    cin >> k >> w >> h;
    int wh[h][w];
    int con[k + 1][h][w];
    int ans = INT_MAX;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> wh[i][j];
            for (int t = 0; t <= k; t++)
            {
                con[t][i][j] = INT_MAX;
            }
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});
    con[0][0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second.first;
        int ck = q.front().second.second;
        q.pop();
        if (x == h - 1 &&y == w - 1)
        {
            if (ans > con[ck][x][y])
                ans = con[ck][x][y];
            continue;
        }
        for (int i = 4; i < 12; i++)
        {
            if (x + dx[i] >= 0 && x + dx[i] < h && y + dy[i] >= 0 && y + dy[i] < w)
            {
                if (wh[x + dx[i]][y + dy[i]] != 1 && con[ck + 1][x + dx[i]][y + dy[i]] > c + 1 && ck + 1 <= k)
                {
                    con[ck + 1][x + dx[i]][y + dy[i]] = c + 1;
                    q.push({{x + dx[i], y + dy[i]}, {c + 1, ck + 1}});
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] >= 0 && x + dx[i] < h && y + dy[i] >= 0 && y + dy[i] < w)
            {
                if (wh[x + dx[i]][y + dy[i]] != 1 && con[ck][x + dx[i]][y + dy[i]] > c + 1)
                {
                    con[ck][x + dx[i]][y + dy[i]] = c + 1;
                    q.push({{x + dx[i], y + dy[i]}, {c + 1, ck}});
                }
            }
        }
    }
    if (ans == INT_MAX)
        cout
            << -1;
    else
        cout << ans;
}