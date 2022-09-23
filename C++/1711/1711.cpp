#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> v;
    for (int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long long int d1 = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
                long long int d2 = (v[j].first - v[k].first) * (v[j].first - v[k].first) + (v[j].second - v[k].second) * (v[j].second - v[k].second);
                long long int d3 = (v[k].first - v[i].first) * (v[k].first - v[i].first) + (v[k].second - v[i].second) * (v[k].second - v[i].second);
                if (d1 + d2 == d3 || d2 + d3 == d1 || d1 + d3 == d2)
                    ans++;
            }
        }
    }
    cout << ans;
}