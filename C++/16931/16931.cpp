#include <iostream>
using namespace std;
int nm[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nm[i][j];
        }
    }
    int ans = n * m * 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nm[i - 1][j] < nm[i][j])
                ans += nm[i][j] - nm[i - 1][j];
            if (nm[i + 1][j] < nm[i][j])
                ans += nm[i][j] - nm[i + 1][j];
            if (nm[i][j + 1] < nm[i][j])
                ans += nm[i][j] - nm[i][j + 1];
            if (nm[i][j - 1] < nm[i][j])
                ans += nm[i][j] - nm[i][j - 1];
        }
    }
    cout << ans;
}