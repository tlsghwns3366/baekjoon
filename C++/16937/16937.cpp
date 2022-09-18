#include <iostream>
#include <vector>
using namespace std;
int h, w;
int n;
vector<pair<int, int>> v[100];
bool bb[100];
int bn[2];
int ans = 0;

void f(int c)
{
    if (c == 2)
    {
        int s1 = bn[0];
        int s2 = bn[1];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (v[s1][i].first + v[s2][j].first <= w)
                {
                    if (max(v[s1][i].second, v[s2][j].second) <= h)
                    {
                        ans = ans < (v[s1][i].first * v[s1][i].second) + (v[s2][j].first * v[s2][j].second) ? (v[s1][i].first * v[s1][i].second) + (v[s2][j].first * v[s2][j].second) : ans;
                    }
                }
                if (v[s1][i].second + v[s2][j].second <= h)
                {
                    if (max(v[s1][i].first, v[s2][j].first) <= w)
                    {
                        ans = ans < (v[s1][i].first * v[s1][i].second) + (v[s2][j].first * v[s2][j].second) ? (v[s1][i].first * v[s1][i].second) + (v[s2][j].first * v[s2][j].second) : ans;
                    }
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!bb[i])
        {
            bb[i] = true;
            bn[c] = i;
            f(c + 1);
            bb[i] = false;
        }
    }
}
int main()
{
    cin >> h >> w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i].push_back({a, b});
        v[i].push_back({b, a});
    }
    f(0);
    cout << ans;
}