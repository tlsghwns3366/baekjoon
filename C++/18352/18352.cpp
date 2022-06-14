#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> v[n + 1];
    int d[n + 1];
    bool bn[n + 1];
    for (int i = 1; i <= n; i++)
    {
        d[i] = 987654321;
        bn[i] = false;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    d[x] = 0;
    bn[x] = true;
    queue<pair<int, int>> q;
    q.push({x, 0});
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < v[a].size(); i++)
        {
            if (!bn[v[a][i]])
            {
                if (d[a] + 1 < d[v[a][i]])
                {
                    bn[v[a][i]] = true;
                    d[v[a][i]] = d[a] + 1;
                    q.push({v[a][i], (d[a] + 1)});
                }
            }
        }
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == k)
        {
            cout << i << "\n";
            ans = true;
        }
    }
    if (!ans)
        cout << -1;
}