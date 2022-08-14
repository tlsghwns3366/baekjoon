#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    while (true)
    {
        int n, m;
        float tm;
        cin >> n >> tm;
        if (n == 0 && tm == 0)
            break;
        m = tm * 100 + 0.5;
        int dp[10000];
        vector<pair<int, int>> v;
        fill(dp, dp + 10001, 0);
        for (int i = 0; i < n; i++)
        {
            int a;
            float b;
            cin >> a >> b;
            v.push_back({a, b * 100 + 0.5});
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = v[i].second; j <= m; j++)
            {
                dp[j] = dp[j] > dp[j - v[i].second] + v[i].first ? dp[j] : dp[j - v[i].second] + v[i].first;
                if (ans < dp[j])
                    ans = dp[j];
            }
        }
        cout << ans << "\n";
    }
}