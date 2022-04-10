#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m;
vector<pair<int, int>> v[10001];
int start, eend;
bool bfs(int bfsstart)
{
    queue<int> q;
    bool qb[n + 1];
    fill(qb, qb + n + 1, false);
    q.push(start);
    qb[start] = true;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (a == eend)
            return true;
        for (int i = 0; i < v[a].size(); i++)
        {
            if (!qb[v[a][i].first])
            {
                if (v[a][i].second >= bfsstart)
                {
                    qb[v[a][i].first] = true;
                    q.push(v[a][i].first);
                }
            }
        }
    }
    return qb[eend];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> start >> eend;
    int l = 1;
    int r = 1000000000;
    while (l <= r)
    {
        int c = (l + r) / 2;
        if (bfs(c))
        {
            l = c + 1;
        }
        else
        {
            r = c - 1;
        }
    }

    cout << r;
}