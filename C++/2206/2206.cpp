#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int nx[4] = {0, 1, 0, -1};
int ny[4] = {-1, 0, 1, 0};
int ans = INT_MAX;

void f(int **nm, int n, int m)
{
    int bb[n][m][2];
    fill(&bb[0][0][0], &bb[n - 1][m - 1][2], INT_MAX);
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    bb[0][0][0] = 1;
    while (!q.empty())
    {
        pair<pair<int, int>, int> temp;
        temp.first.first = q.front().first.first;
        temp.first.second = q.front().first.second;
        temp.second = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (temp.first.first + nx[i] >= 0 && temp.first.first + nx[i] < n && temp.first.second + ny[i] >= 0 && temp.first.second + ny[i] < m)
            {
                if (bb[temp.first.first + nx[i]][temp.first.second + ny[i]][temp.second] > bb[temp.first.first][temp.first.second][temp.second] + 1)
                {
                    if (nm[temp.first.first + nx[i]][temp.first.second + ny[i]] == 0)
                    {
                        bb[temp.first.first + nx[i]][temp.first.second + ny[i]][temp.second] = bb[temp.first.first][temp.first.second][temp.second] + 1;
                        q.push(make_pair(make_pair(temp.first.first + nx[i], temp.first.second + ny[i]), temp.second));
                    }
                    else if (nm[temp.first.first + nx[i]][temp.first.second + ny[i]] == 1 && temp.second != 1)
                    {
                        if (bb[temp.first.first + nx[i]][temp.first.second + ny[i]][1] > bb[temp.first.first][temp.first.second][temp.second] + 1)
                        {
                            bb[temp.first.first + nx[i]][temp.first.second + ny[i]][1] = bb[temp.first.first][temp.first.second][temp.second] + 1;
                            q.push(make_pair(make_pair(temp.first.first + nx[i], temp.first.second + ny[i]), 1));
                        }
                    }
                }
            }
        }
    }
    if (bb[n - 1][m - 1][0] < ans)
        ans = bb[n - 1][m - 1][0];
    if (bb[n - 1][m - 1][1] < ans)
        ans = bb[n - 1][m - 1][1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    int **nm = new int *[n];
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        nm[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            nm[i][j] = a[j] - '0';
        }
    }

    f(nm, n, m);

    if (ans == INT_MAX)
        cout << "-1";
    else
        cout << ans;
}