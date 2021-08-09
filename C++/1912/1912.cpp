#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}
int main()
{
    int n;
    cin >> n;
    int *s = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int *dp = new int[n]{0};
    dp[0] = s[0];
    int maxsum = s[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(s[i], dp[i - 1] + s[i]);
        if (maxsum < dp[i])
            maxsum = dp[i];
    }
    cout << maxsum;
}