#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, s;
int nn[21][21];
int cc[21][21];
bool bb[21][21];
vector<pair<int, int>> p;
vector<pair<int, int>> t;
int f(int a, int b)
{
    fill(&bb[1][1], &bb[20][21], false);
    fill(&cc[1][1], &cc[20][21], 987654321);
    queue<pair<int, int>> q;
    q.push({a, b});
    bb[a][b] = true;
    cc[a][b] = 0;
    int minx = 987654321;
    if (nn[a][b] != 0)
        minx = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] <= n && x + dx[i] > 0 && y + dy[i] <= n && y + dy[i] > 0)
            {
                if (!bb[x + dx[i]][y + dy[i]] && cc[x + dx[i]][y + dy[i]] > cc[x][y] + 1 && nn[x + dx[i]][y + dy[i]] != 1)
                {
                    bb[x + dx[i]][y + dy[i]] = true;
                    cc[x + dx[i]][y + dy[i]] = cc[x][y] + 1;
                    q.push({x + dx[i], y + dy[i]});
                    if (nn[x + dx[i]][y + dy[i]] != 0 && minx > cc[x + dx[i]][y + dy[i]])
                        minx = cc[x + dx[i]][y + dy[i]];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (minx == cc[i][j] && nn[i][j] != 0 && minx != 987654321)
            {
                int temp = nn[i][j];
                nn[i][j] = 0;
                s -= minx;
                m--;
                return temp - 2;
            }
        }
    }
    return -1;
}
int tmove(int a)
{
    fill(&bb[1][1], &bb[20][21], false);
    fill(&cc[1][1], &cc[20][21], 987654321);
    queue<pair<int, int>> q;
    q.push({p[a].first, p[a].second});
    bb[p[a].first][p[a].second] = true;
    cc[p[a].first][p[a].second] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] <= n && x + dx[i] > 0 && y + dy[i] <= n && y + dy[i] > 0)
            {
                if (!bb[x + dx[i]][y + dy[i]] && cc[x + dx[i]][y + dy[i]] > cc[x][y] + 1 && nn[x + dx[i]][y + dy[i]] != 1)
                {
                    bb[x + dx[i]][y + dy[i]] = true;
                    cc[x + dx[i]][y + dy[i]] = cc[x][y] + 1;
                    q.push({x + dx[i], y + dy[i]});
                }
            }
        }
    }
    s -= cc[t[a].first][t[a].second];
    return cc[t[a].first][t[a].second];
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nn[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < m; i++)
    {
        int px, py;
        int tx, ty;
        cin >> px >> py >> tx >> ty;
        nn[px][py] = i + 2;
        p.push_back({px, py});
        t.push_back({tx, ty});
    }
    bool ans = false;
    while (true)
    {
        int taxi = f(a, b);
        if (taxi == -1)
        {
            break;
        }
        int plus = tmove(taxi);
        if (s < 0)
        {
            ans = true;
            break;
        }
        s += plus * 2;
        a = t[taxi].first;
        b = t[taxi].second;
    }
    if (ans || m != 0)
        cout << "-1";
    else
        cout << s;
}