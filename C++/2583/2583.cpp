#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool **b;
int n, m, k;
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int ans;
void f(int x, int y)
{
    b[x][y] = true;
    ans++;
    for (int i = 0; i < 4; i++)
    {
        if (x + nx[i] < m && x + nx[i] >= 0 && y + ny[i] < n && y + ny[i] >= 0)
        {
            if (!b[x + nx[i]][y + ny[i]])
                f(x + nx[i], y + ny[i]);
        }
    }
}
int main()
{
    cin >> m >> n >> k;
    b = new bool *[m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new bool[n];
        fill(b[i], b[i] + n, false);
    }
    for (int i = 0; i < k; i++)
    {
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
        {
            for (int k = y1; k < y2; k++)
            {
                b[k][j] = true;
            }
        }
    }
    int c = 0;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!b[i][j])
            {
                ans = 0;
                c++;
                f(i, j);
                v.push_back(ans);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << c << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}