#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int xx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    int A[n + 1][n + 1];
    int nn[n + 1][n + 1];
    fill(&nn[0][0], &nn[n + 1][n + 1], 5);
    vector<int> q[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        q[x][y].push_back(z);
    }
    for (int w = 0; w < k; w++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!q[i][j].empty())
                {
                    int pl = 0;
                    vector<int> tq;
                    sort(q[i][j].begin(), q[i][j].end());
                    for (int v = 0; v < q[i][j].size(); v++)
                    {

                        if (nn[i][j] - q[i][j][v] >= 0)
                        {
                            nn[i][j] = nn[i][j] - q[i][j][v];
                            tq.push_back(q[i][j][v] + 1);
                        }
                        else
                        {
                            pl += q[i][j][v] / 2;
                        }
                    }
                    q[i][j].clear();
                    for (int v = 0; v < tq.size(); v++)
                    {
                        q[i][j].push_back(tq[v]);
                    }
                    nn[i][j] += pl;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!q[i][j].empty())
                {
                    for (int v = 0; v < q[i][j].size(); v++)
                    {
                        if (q[i][j][v] % 5 == 0)
                        {
                            for (int t = 0; t < 8; t++)
                            {
                                if (i + xx[t] >= 1 && i + xx[t] <= n && j + yy[t] >= 1 && j + yy[t] <= n)
                                {
                                    q[i + xx[t]][j + yy[t]].push_back(1);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                nn[i][j] += A[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans += q[i][j].size();
        }
    }
    cout << ans;
}