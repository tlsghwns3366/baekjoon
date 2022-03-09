#include <iostream>
#include <vector>
using namespace std;
int n, m, h;
bool **mn;
vector<vector<int>> v(11, vector<int>(31, 0));
bool f(int line, int c, int x)
{
    if (line == c)
    {
        for (int i = 1; i <= n; i++)
        {
            int a = i;
            for (int j = 1; j <= h; j++)
            {
                if (v[a][j] != 0)
                    a = v[a][j];
            }
            if (a != i)
                return false;
        }
        return true;
    }

    for (int i = x; i < n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (v[i][j] == 0 && v[i + 1][j] == 0)
            {
                v[i][j] = i + 1;
                v[i + 1][j] = i;
                if (f(line, c + 1, i))
                    return true;
                v[i][j] = 0;
                v[i + 1][j] = 0;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        v[b][a] = b + 1;
        v[b + 1][a] = b;
    }
    int ans = -1;
    for (int i = 0; i <= 3; i++)
    {
        if (f(i, 0, 1))
        {
            ans = i;
            break;
        }
    }
    cout << ans;
}