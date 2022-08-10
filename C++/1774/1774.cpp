#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, m;
int nn[1001];
vector<pair<pair<int, int>, double>> v;
pair<long long, long long> xy[1001];

int f(int a)
{
    if (nn[a] == a)
        return a;
    else
        return nn[a] = f(nn[a]);
}
bool cmp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b)
{
    return a.second < b.second;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        nn[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> xy[i].first >> xy[i].second;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double c = sqrt(pow((xy[i].first - xy[j].first), 2) + pow((xy[i].second - xy[j].second), 2));
            v.push_back({{i, j}, c});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (f(x) == f(y))
            continue;
        nn[f(y)] = f(x);
    }
    double ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int a = f(v[i].first.first);
        int b = f(v[i].first.second);
        if (a == b)
            continue;
        nn[b] = a;
        ans += v[i].second;
    }
    printf("%.2f", ans);
}