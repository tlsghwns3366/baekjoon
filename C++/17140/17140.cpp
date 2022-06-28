#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int nn[101][101];
int x = 3;
int y = 3;
int ans = 0;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
void fr()
{
    int ty = y;
    for (int i = 1; i <= x; i++)
    {
        int temp[101] = {
            0,
        };
        for (int j = 1; j <= y; j++)
        {
            temp[nn[i][j]]++;
        }

        vector<pair<int, int>> v;
        for (int k = 1; k < 101; k++)
        {
            if (temp[k] != 0)
                v.push_back({k, temp[k]});
        }
        ty = ty < v.size() * 2 ? v.size() * 2 : ty;
        sort(v.begin(), v.end(), cmp);

        int p = 1;
        for (int k = 0; k < v.size(); k++)
        {
            nn[i][p] = v[k].first;
            nn[i][p + 1] = v[k].second;
            p += 2;
        }
        for (int k = p; k <= 101; k++)
        {
            nn[i][k] = 0;
        }
    }
    y = ty;
}
void fc()
{
    int tx = x;
    for (int i = 1; i <= y; i++)
    {
        int temp[101] = {
            0,
        };
        for (int j = 1; j <= x; j++)
        {
            temp[nn[j][i]]++;
        }

        vector<pair<int, int>> v;
        for (int k = 1; k < 101; k++)
        {
            if (temp[k] != 0)
                v.push_back({k, temp[k]});
        }
        tx = tx < v.size() * 2 ? v.size() * 2 : tx;
        sort(v.begin(), v.end(), cmp);

        int p = 1;
        for (int k = 0; k < v.size(); k++)
        {
            nn[p][i] = v[k].first;
            nn[p + 1][i] = v[k].second;
            p += 2;
        }
        for (int k = p; k <= 101; k++)
        {
            nn[k][i] = 0;
        }
    }
    x = tx;
}
int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> nn[i][j];
        }
    }
    while (true)
    {
        if (nn[r][c] == k)
            break;
        if (ans > 100)
        {
            ans = -1;
            break;
        }
        if (x >= y)
            fr();
        else
            fc();
        ans++;
    }
    cout << ans;
}