#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int nv[1001];
int ans = 0;
vector<pair<pair<int, int>, int>> v;
int f(int a)
{
    if (nv[a] == a)
        return a;
    else
        return nv[a] = f(nv[a]);
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        nv[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        int a = f(v[i].first.first);
        int b = f(v[i].first.second);
        int c = v[i].second;
        if (a == b)
            continue;
        if (a < b)
            nv[b] = a;
        else
            nv[a] = b;
        ans += c;
    }
    cout << ans;
}