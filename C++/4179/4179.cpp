#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int r, c;
    cin >> r >> c;
    char rc[r][c];
    int jans[r][c];
    int fans[r][c];
    bool jb[r][c];
    bool fb[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> rc[i][j];
            jb[i][j] = false;
            fb[i][j] = false;
            jans[i][j] = 987654321;
            fans[i][j] = 987654321;
        }
    }

    queue<pair<int, int>> ji;
    queue<pair<int, int>> fi;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == 'J')
            {
                ji.push({i, j});
                jb[i][j] = true;
                jans[i][j] = 0;
            }
            if (rc[i][j] == 'F')
            {
                fi.push({i, j});
                fb[i][j] = true;
                fans[i][j] = 0;
            }
        }
    }
    while (!ji.empty())
    {
        int x = ji.front().first;
        int y = ji.front().second;
        ji.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < r && x + dx[i] >= 0 && y + dy[i] < c && y + dy[i] >= 0)
            {
                if (rc[x + dx[i]][y + dy[i]] != '#')
                {
                    if (!jb[x + dx[i]][y + dy[i]])
                    {
                        jans[x + dx[i]][y + dy[i]] = jans[x + dx[i]][y + dy[i]] < jans[x][y] + 1 ? jans[x + dx[i]][y + dy[i]] : jans[x][y] + 1;
                        jb[x + dx[i]][y + dy[i]] = true;
                        ji.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
    }
    while (!fi.empty())
    {
        int x = fi.front().first;
        int y = fi.front().second;
        fi.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < r && x + dx[i] >= 0 && y + dy[i] < c && y + dy[i] >= 0)
            {
                if (rc[x + dx[i]][y + dy[i]] != '#')
                {
                    if (!fb[x + dx[i]][y + dy[i]])
                    {
                        fans[x + dx[i]][y + dy[i]] = fans[x + dx[i]][y + dy[i]] < fans[x][y] + 1 ? fans[x + dx[i]][y + dy[i]] : fans[x][y] + 1;
                        fb[x + dx[i]][y + dy[i]] = true;
                        fi.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
    }
    int ans = 987654321;
    for (int i = 0; i < c; i++)
    {
        if (jans[0][i] < ans && jans[0][i] < fans[0][i])
            ans = jans[0][i];
        if (jans[r - 1][i] < ans && jans[r - 1][i] < fans[r - 1][i])
            ans = jans[r - 1][i];
    }
    for (int i = 0; i < r; i++)
    {
        if (jans[i][0] < ans && jans[i][0] < fans[i][0])
            ans = jans[i][0];
        if (jans[i][c - 1] < ans && jans[i][c - 1] < fans[i][c - 1])
            ans = jans[i][c - 1];
    }
    if (ans != 987654321)
        cout << ans + 1;
    else
        cout << "IMPOSSIBLE";
}