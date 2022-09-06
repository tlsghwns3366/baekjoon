#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int w = 0; w < t; w++)
    {
        int n, d, c;
        cin >> n >> d >> c;
        int nc[n + 1];
        bool nb[n + 1];
        fill(nc, nc + n + 1, 987654321);
        fill(nb, nb + n + 1, false);
        vector<pair<int, int>> v[n + 1];
        for (int i = 0; i < d; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            v[y].push_back({x, z});
        }
        queue<int> q;
        nc[c] = 0;
        nb[c] = true;
        q.push(c);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < v[x].size(); i++)
            {
                if (nc[v[x][i].first] > nc[x] + v[x][i].second)
                {
                    nc[v[x][i].first] = nc[x] + v[x][i].second;
                    nb[v[x][i].first] = true;
                    q.push(v[x][i].first);
                }
            }
        }
        int ans1 = 0;
        int ans2 = 0;

        for (int i = 1; i <= n; i++)
        {
            if (nb[i])
            {
                ans1++;
                ans2 = ans2 < nc[i] ? nc[i] : ans2;
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}