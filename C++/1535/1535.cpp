#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n + 1];
    int B[n + 1];
    int dp[n + 1][100];

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (A[i] <= j)
            {
                dp[i][j] = dp[i - 1][j] > dp[i - 1][j - A[i]] + B[i] ? dp[i - 1][j] : dp[i - 1][j - A[i]] + B[i];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][99];
}