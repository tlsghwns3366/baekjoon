#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v[10001];
int f(int a, bool *b)
{
    if (v[a].size() == 0)
    {
        return 0;
    }
    b[a] = true;
    int ans = 0;
    for (int i = 0; i < v[a].size(); i++)
    {
        if (!b[v[a][i].first])
        {
            int temp = f(v[a][i].first, b);
            ans = ans > temp + v[a][i].second ? ans : temp + v[a][i].second;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool tempn[n + 1];
        fill(tempn, tempn + n + 1, false);
        int temp = f(i, tempn);
        ans = temp > ans ? temp : ans;
    }
    cout << ans;
}