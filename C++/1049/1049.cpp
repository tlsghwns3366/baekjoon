#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    vector<pair<int, int>> v2;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        v2.push_back({b, a});
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    int ans = 0;
    int ans2 = 0;
    int ans3 = 0;
    ans += (n / 6) * v[0].first + (n % 6) * v2[0].first;
    ans2 += n * v2[0].first;
    ans3 += (n / 6 + 1) * v[0].first;
    ans = ans < ans2 ? ans : ans2;
    ans = ans < ans3 ? ans : ans3;
    cout << ans;
}