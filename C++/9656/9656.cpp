#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string dp[1010];
    dp[1] = "CY";
    dp[2] = "SK";
    dp[3] = "CY";
    for (int i = 4; i <= n; i++)
    {
        if (dp[i - 1] == "CY" || dp[i - 3] == "CY")
            dp[i] = "SK";
        else
            dp[i] = "CY";
    }
    cout << dp[n];
}