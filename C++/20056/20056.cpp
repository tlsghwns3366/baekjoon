#include <iostream>
#include <vector>
using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
struct MagicShark
{
    int mi;
    int si;
    int di;
};
vector<MagicShark> v[1001][51][51];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        MagicShark tm;
        cin >> a >> b >> tm.mi >> tm.si >> tm.di;
        v[0][a - 1][b - 1].push_back(tm);
    }
    for (int tk = 0; tk < k; tk++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[tk][i][j].size() != 0)
                {
                    MagicShark tm;
                    for (int q = 0; q < v[tk][i][j].size(); q++)
                    {
                        tm.di = v[tk][i][j][q].di;
                        tm.mi = v[tk][i][j][q].mi;
                        tm.si = v[tk][i][j][q].si;
                        int x = (n + (i + tm.si * dx[tm.di]) % n) % n;
                        int y = (n + (j + tm.si * dy[tm.di]) % n) % n;
                        v[tk + 1][x][y].push_back(tm);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[tk + 1][i][j].size() >= 2)
                {
                    MagicShark tm;
                    tm.di = v[tk + 1][i][j][0].di;
                    tm.mi = v[tk + 1][i][j][0].mi;
                    tm.si = v[tk + 1][i][j][0].si;
                    bool dtest = false;
                    for (int q = 1; q < v[tk + 1][i][j].size(); q++)
                    {
                        if ((tm.di % 2) != (v[tk + 1][i][j][q].di % 2))
                            dtest = true;
                        tm.mi += v[tk + 1][i][j][q].mi;
                        tm.si += v[tk + 1][i][j][q].si;
                    }
                    tm.mi /= 5;
                    tm.si /= v[tk + 1][i][j].size();
                    if (tm.mi == 0)
                    {
                        v[tk + 1][i][j].clear();
                        continue;
                    }
                    tm.di = 0;
                    v[tk + 1][i][j].clear();
                    if (dtest)
                    {
                        for (int w = 1; w < 8; w += 2)
                        {
                            tm.di = w;
                            v[tk + 1][i][j].push_back(tm);
                        }
                    }
                    else
                    {
                        for (int w = 0; w < 8; w += 2)
                        {
                            tm.di = w;
                            v[tk + 1][i][j].push_back(tm);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[k][i][j].size() != 0)
            {
                for (int q = 0; q < v[k][i][j].size(); q++)
                {
                    ans += v[k][i][j][q].mi;
                }
            }
        }
    }
    cout << ans;
}