#include <iostream>
#include <vector>
using namespace std;
int nd[501];
int main()
{
    int tc;
    cin >> tc;
    for (int tcc = 0; tcc < tc; tcc++)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vector<pair<pair<int, int>, int>> v;
        for (int i = 1; i <= n; i++)
        {
            nd[i] = 987654321;
        }
        nd[1] = 0;
        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, t});
            v.push_back({{e, s}, t});
        }
        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back({{s, e}, -t});
        }
        int ans = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                int a = v[j].first.first;
                int b = v[j].first.second;
                int c = v[j].second;
                if (nd[a] + c < nd[b])
                {
                    if (i == n)
                        ans = true;
                    nd[b] = nd[a] + c;
                }
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}