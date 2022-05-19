#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, w, l;
    cin >> n >> w >> l;
    int da = 0;
    int ans = 0;
    queue<pair<int, int>> ti;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (da + a <= l)
        {
            da += a;
            ans++;
            ti.push({ans + w, a});
            while (!ti.empty() && ti.front().first <= ans)
            {
                da -= ti.front().second;
                ti.pop();
            }
        }
        else
        {
            while (!ti.empty() && (da + a > l || ti.size() == w))
            {
                ans = ti.front().first;
                da -= ti.front().second;
                ti.pop();
            }
            da += a;
            ti.push({ans + w, a});
        }
    }
    while (!ti.empty())
    {
        ans = ti.front().first;
        ti.pop();
    }
    cout << ans;
}