#include <iostream>
using namespace std;
int dp[31][15001];
int main()
{
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int m;
    cin >> m;
    int mm[m];
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 15000; j++)
        {
            if (nn[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] > dp[i - 1][j - nn[i - 1]] + nn[i - 1] ? dp[i - 1][j] : dp[i - 1][j - nn[i - 1]] + nn[i - 1];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= 15000; j++)
        {
            if (j + mm[i] > 15000)
            {
                cout << "N ";
                break;
            }
            else if (dp[n][j + mm[i]] == dp[n][j] + mm[i])
            {
                cout << "Y ";
                break;
            }
        }
    }
}