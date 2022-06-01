#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string dp[1010];
    dp[1] = "SK";
    dp[2] = "CY";
    dp[3] = "SK";
    dp[4] = "SK";
    for (int i = 5; i <= n; i++)
    {
        if (dp[i - 1] == "CY" || dp[i - 3] == "CY" || dp[i - 4] == "CY")
            dp[i] = "SK";
        else
            dp[i] = "CY";
    }
    cout << dp[n];
}