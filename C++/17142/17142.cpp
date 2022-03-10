#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int vsize;
bool *vb;
int ans = INT_MAX;
int nn[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
void f(int end, int c, int a)
{
    if (end == c)
    {
        int temp[n + 1][n + 1];
        bool tb[n + 1][n + 1];
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nn[i][j] == 1)
                    temp[i][j] = -1;
                else if (nn[i][j] == 2)
                    temp[i][j] = 0;
                else
                {
                    temp[i][j] = INT_MAX;
                    count++;
                }
                tb[i][j] = false;
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < vsize; i++)
        {
            if (vb[i])
            {
                q.push({v[i].first, v[i].second});
                tb[v[i].first][v[i].second] = true;
            }
        }
        int smax = -1;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (count == 0)
                break;
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] <= n && x + dx[i] >= 1 && y + dy[i] <= n && y + dy[i] >= 1)
                {
                    if (temp[x + dx[i]][y + dy[i]] != -1 && !tb[x + dx[i]][y + dy[i]])
                    {
                        tb[x + dx[i]][y + dy[i]] = true;
                        if (temp[x + dx[i]][y + dy[i]] == 0)
                            temp[x + dx[i]][y + dy[i]] = temp[x][y] + 1;
                        else
                            count--;
                        temp[x + dx[i]][y + dy[i]] = min(temp[x + dx[i]][y + dy[i]], temp[x][y] + 1);
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (temp[i][j] == INT_MAX)
                    return;
                else if (temp[i][j] > smax)
                    smax = temp[i][j];
            }
        }
        if (smax == -1)
            return;
        else
        {
            ans = min(ans, smax);
            return;
        }
    }
    for (int i = a; i < vsize; i++)
    {
        vb[i] = true;
        f(end, c + 1, i + 1);
        vb[i] = false;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 2)
                v.push_back({i, j});
        }
    }
    vb = new bool[v.size()];
    fill(vb, vb + v.size(), false);
    vsize = v.size();
    f(m, 0, 0);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}