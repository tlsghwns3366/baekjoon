#include <iostream>
using namespace std;
int dp[102][102][102];
int f(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}
int main()
{
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s3.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            for (int k = 1; k <= s1.length(); k++)
            {
                if (s3[i - 1] == s2[j - 1] && s2[j - 1] == s1[k - 1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = f(f(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }

    cout << dp[s3.length()][s2.length()][s1.length()];
}