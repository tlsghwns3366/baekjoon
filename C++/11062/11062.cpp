#include <iostream>
using namespace std;
int n;
int nn[1001];
int dp[1001][1001];
int f(int a, int b)
{
    if (dp[a][b] != 0)
        return dp[a][b];
    if (a >= b)
    {
        if ((n - (a + b)) % 2)
            return dp[a][b] = nn[a];
        else
            return dp[a][b] = 0;
    }

    if ((n - (a + b)) % 2)
        dp[a][b] = max((f(a + 1, b) + nn[a]), (f(a, b - 1) + nn[b]));
    else
        dp[a][b] = min(f(a + 1, b), f(a, b - 1));
    return dp[a][b];
}
int main()
{
    int t;
    cin >> t;
    for (int w = 0; w < t; w++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> nn[i];
        }
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = 0;
            }
        }
        cout << f(0, n - 1)<<"\n";
    }
}