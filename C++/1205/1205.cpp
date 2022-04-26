#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = -1;
    sort(v.rbegin(), v.rend());
    if (n == 0)
    {
        ans = 1;
        cout << ans;
    }
    else if (v.back() >= m && n == p)
    {
        cout << ans;
    }
    else
    {
        v.push_back(m);
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == m)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans;
    }
}