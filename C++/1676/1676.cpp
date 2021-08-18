#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[501] = {
        1,
    };
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
        while (dp[i] % 10 == 0)
        {
            count++;
            dp[i] = dp[i] / 10;
        }
        dp[i] = dp[i] % 10000;
    }
    cout << count << endl;
}