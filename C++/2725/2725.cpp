#include <iostream>
using namespace std;
int dp[1002];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int c;
    cin >> c;
    for (int i = 0; i <= 1000; i++)
    {
        if (i != 0)
            dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++)
        {
            if (gcd(i, j) == 1)
                dp[i] += 2;
        }
    }
    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] + 1 << "\n";
    }
}