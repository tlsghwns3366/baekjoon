#include <iostream>
#include <queue>
using namespace std;
int n, l, r;
int **nn;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
bool f()
{
    bool bb[n][n];
    fill(&bb[0][0], &bb[n - 1][n], false);
    bool temp = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!bb[i][j])
            {
                bb[i][j] = true;
                queue<pair<int, int>> q;
                queue<pair<int, int>> qn;
                q.push({i, j});
                int sum = nn[i][j];
                int count = 1;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    qn.push({x, y});
                    for (int z = 0; z < 4; z++)
                    {
                        if (x + dx[z] >= 0 && x + dx[z] < n && y + dy[z] >= 0 && y + dy[z] < n)
                        {
                            int lr = abs(nn[x][y] - nn[x + dx[z]][y + dy[z]]);
                            if (lr >= l && lr <= r && !bb[x + dx[z]][y + dy[z]])
                            {
                                sum += nn[x + dx[z]][y + dy[z]];
                                count++;
                                bb[x + dx[z]][y + dy[z]] = true;
                                q.push({x + dx[z], y + dy[z]});
                                temp = true;
                            }
                        }
                    }
                }
                int sumcount = sum / count;
                while (!qn.empty())
                {
                    int x = qn.front().first;
                    int y = qn.front().second;
                    nn[x][y] = sumcount;
                    qn.pop();
                }
            }
        }
    }
    return temp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    while (f())
    {
        ans++;
    }
    cout << ans;
}