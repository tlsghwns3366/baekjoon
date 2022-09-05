#include <iostream>
using namespace std;
bool dp[2001][2001];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int nn[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> nn[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = true;
        dp[1][i] = true;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j + i - 1 <= n; j++)
        {
            if (nn[j] == nn[j + i - 1])
            {
                dp[i][j] += dp[i - 2][j + 1];
            }
        }
    }
    for (int q = 0; q < m; q++)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[e - s + 1][s] << "\n";
    }
}