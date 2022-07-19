#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int home[100001];
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}
int f(int a)
{
    if (home[a] == a)
        return a;
    else
        return home[a] = f(home[a]);
}
int main()
{
    int ans = 0;
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        home[i] = i;
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
        {
            home[b] = a;
        }
        else
        {
            home[a] = b;
        }
        if (sum < c)
            sum = c;
        ans += c;
    }
    cout << ans - sum;
}