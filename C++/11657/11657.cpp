#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int n, m;
long long int nd[501];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        nd[i] = INF;
    }
    nd[1] = 0;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int a = v[j].first.first;
            int b = v[j].first.second;
            int c = v[j].second;
            if (nd[a] == INF)
                continue;
            if (nd[a] + c < nd[b])
            {
                if (i == n)
                    ans = true;
                nd[b] = nd[a] + c;
            }
        }
    }
    if (ans)
    {
        cout << -1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (nd[i] == INF)
                cout << -1 << "\n";
            else
                cout << nd[i] << "\n";
        }
    }
}