#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[10001];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.first < b.first.first;
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i <= d; i++)
    {
        dp[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        dp[v[i].first.second] = min(dp[v[i].first.second], dp[v[i].first.first] + v[i].second);
        for (int j = v[i].first.second; j <= d; j++)
        {
            dp[j] = min(dp[j - 1] + 1, dp[j]);
        }
    }
    cout << dp[d];
}