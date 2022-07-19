#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, e;
int nv[10001];
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
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        nv[i] = i;
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
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