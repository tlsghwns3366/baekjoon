#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, m;
int ans;
int **nn;
vector<pair<int, int>> v;
vector<pair<int, int>> chicken;
bool *chickenP;
void f(int mc, int start, int c)
{
    if (mc == start)
    {
        int sum = 0;
        for (int q = 0; q < v.size(); q++)
        {
            int x = v[q].first;
            int y = v[q].second;
            int temp = INT_MAX;
            for (int i = 0; i < chicken.size(); i++)
            {
                if (chickenP[i])
                {
                    temp = min(temp, abs(x - chicken[i].first) + abs(y - chicken[i].second));
                }
            }
            sum += temp;
        }
        if (ans > sum)
            ans = sum;
        return;
    }
    for (int i = c; i < chicken.size(); i++)
    {
        if (!chickenP[i])
        {
            chickenP[i] = true;
            f(mc, start + 1, i + 1);
            chickenP[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    nn = new int *[n];
    ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 1)
                v.push_back({i, j});
            if (nn[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    chickenP = new bool[chicken.size()];
    fill(chickenP, chickenP + chicken.size(), false);
    for (int i = 1; i <= m; i++)
    {
        f(i, 0, 0);
    }
    cout << ans;
}