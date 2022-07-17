#include <iostream>
#include <algorithm>
using namespace std;
int nn[3001];
int f(int a)
{
    if (nn[a] == a)
        return a;
    else
        return nn[a] = f(nn[a]);
}
int main()
{
    int T;
    cin >> T;
    for (int q = 0; q < T; q++)
    {
        int n;
        cin >> n;
        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            nn[i] = i;
        }
        pair<pair<int, int>, int> p[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].first.first >> p[i].first.second >> p[i].second;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int x1 = p[i].first.first;
                int x2 = p[j].first.first;
                int y1 = p[i].first.second;
                int y2 = p[j].first.second;
                int ri = p[i].second + p[j].second;
                if (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) <= ri * ri)
                {
                    if (f(i) == f(j))
                        continue;
                    nn[f(j)] = f(i);
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
}