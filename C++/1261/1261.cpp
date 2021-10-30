#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    int nx[4] = {0, 1, 0, -1};
    int ny[4] = {-1, 0, 1, 0};

    int **nm = new int *[n];
    int bb[n][m];
    fill(&bb[0][0], &bb[n - 1][m], INT_MAX);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        nm[i] = new int[m];
        for (int j = 0; j < s.length(); j++)
        {
            nm[i][j] = s[j] - '0';
        }
    }
    q.push(make_pair(0, 0));
    bb[0][0] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (p.first + ny[i] >= 0 && p.first + ny[i] < n && p.second + nx[i] >= 0 && p.second + nx[i] < m)
            {
                if (nm[p.first + ny[i]][p.second + nx[i]] == 1)
                {
                    if (bb[p.first + ny[i]][p.second + nx[i]] > bb[p.first][p.second] + 1)
                    {
                        bb[p.first + ny[i]][p.second + nx[i]] = bb[p.first][p.second] + 1;
                        q.push(make_pair(p.first + ny[i], p.second + nx[i]));
                    }
                }
                else
                {
                    if (bb[p.first + ny[i]][p.second + nx[i]] > bb[p.first][p.second])
                    {
                        bb[p.first + ny[i]][p.second + nx[i]] = bb[p.first][p.second];
                        q.push(make_pair(p.first + ny[i], p.second + nx[i]));
                    }
                }
            }
        }
    }
    cout << bb[n - 1][m - 1];
}