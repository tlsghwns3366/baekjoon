#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int t;
    cin >> t;
    for (int te = 0; te < t; te++)
    {
        int w, h;
        cin >> w >> h;
        char wh[h][w];
        int qcount[h][w];
        int firecount[h][w];
        queue<pair<int, int>> q;
        queue<pair<int, int>> fire;
        for (int i = 0; i < h; i++)
        {
            string temp;
            cin >> temp;
            for (int j = 0; j < temp.length(); j++)
            {
                wh[i][j] = temp[j];
                qcount[i][j] = 987654321;
                firecount[i][j] = 987654321;
                if (temp[j] == '@')
                {
                    q.push({i, j});
                    qcount[i][j] = 0;
                }
                if (temp[j] == '*')
                {
                    fire.push({i, j});
                    firecount[i][j] = 0;
                }
            }
        }
        while (!fire.empty())
        {
            int x = fire.front().first;
            int y = fire.front().second;
            fire.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < h && x + dx[i] >= 0 && y + dy[i] < w && y + dy[i] >= 0)
                {
                    if (wh[x + dx[i]][y + dy[i]] == '.' && firecount[x + dx[i]][y + dy[i]] > firecount[x][y] + 1)
                    {
                        firecount[x + dx[i]][y + dy[i]] = firecount[x][y] + 1;
                        fire.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < h && x + dx[i] >= 0 && y + dy[i] < w && y + dy[i] >= 0)
                {
                    if (wh[x + dx[i]][y + dy[i]] == '.' && qcount[x + dx[i]][y + dy[i]] > qcount[x][y] + 1)
                    {
                        qcount[x + dx[i]][y + dy[i]] = qcount[x][y] + 1;
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
        int ans = 987654321;
        for (int i = 0; i < h; i++)
        {
            if (wh[i][0] != '#' && qcount[i][0] < firecount[i][0])
                ans = ans > qcount[i][0] ? qcount[i][0] : ans;
            if (wh[i][w - 1] != '#' && qcount[i][w - 1] < firecount[i][w - 1])
                ans = ans > qcount[i][w - 1] ? qcount[i][w - 1] : ans;
        }
        for (int i = 0; i < w; i++)
        {
            if (wh[0][i] != '#' && qcount[0][i] < firecount[0][i])
                ans = ans > qcount[0][i] ? qcount[0][i] : ans;
            if (wh[h - 1][i] != '#' && qcount[h - 1][i] < firecount[h - 1][i])
                ans = ans > qcount[h - 1][i] ? qcount[h - 1][i] : ans;
        }
        if (ans == 987654321)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans + 1 << "\n";
    }
}