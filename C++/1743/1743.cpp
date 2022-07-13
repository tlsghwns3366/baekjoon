#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;
int nm[101][101];
bool bb[101][101];
int f(int a, int b)
{
    int temp = 1;
    bb[a][b] = true;
    for (int i = 0; i < 4; i++)
    {
        if (a + dx[i] <= n && a + dx[i] > 0 && b + dy[i] <= m && b + dy[i] > 0)
        {
            if (nm[a + dx[i]][b + dy[i]] != 0 && !bb[a + dx[i]][b + dy[i]])
            {
                temp += f(a + dx[i], b + dy[i]);
            }
        }
    }
    return temp;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        nm[a][b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nm[i][j] != 0 && !bb[i][j])
            {
                int temp = f(i, j);
                if (ans < temp)
                    ans = temp;
            }
        }
    }
    cout << ans;
}