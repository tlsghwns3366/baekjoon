#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, r;
int item[101];
vector<pair<int, int>> v[101];
int da[101];
int ans = 0;
int main()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int w = 1; w <= n; w++)
    {
        for (int i = 0; i <= n; i++)
        {
            da[i] = 987654321;
        }
        da[w] = 0;
        priority_queue<pair<int, int>> q;
        q.push({0, w});
        while (!q.empty())
        {
            int x = q.top().second;
            q.pop();
            for (int i = 0; i < v[x].size(); i++)
            {
                if (da[x] + v[x][i].second < da[v[x][i].first])
                {
                    da[v[x][i].first] = da[x] + v[x][i].second;
                    q.push({-da[v[x][i].first], v[x][i].first});
                }
            }
        }
        int itemcount = 0;
        for (int i = 1; i <= n; i++)
        {
            if (da[i] <= m)
                itemcount += item[i];
        }
        ans = ans < itemcount ? itemcount : ans;
    }
    cout << ans;
}