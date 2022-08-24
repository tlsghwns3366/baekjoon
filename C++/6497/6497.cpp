#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int nn[200001];
vector<pair<pair<int, int>, long long int>> v;
int f(int a)
{
    if (nn[a] == a)
        return a;
    else
        return nn[a] = f(nn[a]);
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}
int main()
{
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        v.clear();
        for (int i = 0; i <= n; i++)
        {
            nn[i] = i;
        }
        long long int sum = 0;
        for (int i = 0; i < m; i++)
        {
            long long int x, y, z;
            cin >> x >> y >> z;
            sum += z;
            v.push_back({{x, y}, z});
        }
        long long int ans = 0;
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            int a = f(v[i].first.first);
            int b = f(v[i].first.second);
            long long int c = v[i].second;
            if (a == b)
                continue;
            if (a < b)
                nn[b] = a;
            else
                nn[a] = b;
            ans += c;
        }
        cout << sum - ans << "\n";
    }
}