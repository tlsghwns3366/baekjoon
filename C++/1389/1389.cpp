#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int nn[101];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        queue<pair<int, int>> q;
        q.push({i, 0});
        bool qb[n + 1];
        for (int j = 1; j <= n; j++)
        {
            qb[j] = false;
        }
        qb[i] = true;
        while (!q.empty())
        {
            int temp = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int j = 0; j < v[temp].size(); j++)
            {
                if (!qb[v[temp][j]])
                {
                    qb[v[temp][j]] = true;
                    nn[i] += c + 1;
                    q.push({v[temp][j], c + 1});
                }
            }
        }
    }
    int ansc = 987654321;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ansc > nn[i])
        {
            ans = i;
            ansc = nn[i];
        }
    }
    cout << ans;
}