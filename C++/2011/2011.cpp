#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int dp[5001];
    fill(dp, dp + 5001, 0);
    dp[0] = 1;
    dp[1] = 1;

    if (s[0] == '0')
    {
        dp[0] = 0;
        dp[1] = 0;
    }

    for (int i = 1; i < s.length(); i++)
    {
        string temp = "";
        temp = temp + s[i - 1] + s[i];
        int n = temp[1] - '0';
        if (n > 0 && n < 10)
        {
            dp[i + 1] += dp[i];
            dp[i + 1] %= 1000000;
        }
        n = stoi(temp);
        if (n <= 26 && n >= 10)
        {
            dp[i + 1] += dp[i - 1];
            dp[i + 1] %= 1000000;
        }
    }
    cout << dp[s.length()];
}