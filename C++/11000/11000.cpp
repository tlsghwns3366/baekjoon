#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool vb[200001];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int si;
        si = v[i].second;
        if (!vb[i])
        {
            ans++;
            for (int j = i + 1; j < n; j++)
            {
                if (v[j].first >= si && !vb[j])
                {
                    si = v[j].second;
                    vb[j] = true;
                }
            }
        }
    }
    cout << ans;
}