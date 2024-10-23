#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, k;
    cin >> T >> k;
    vector<vector<int>> kn(k + 1, vector<int>(2, 0));
    vector<int> dp(10001);
    for (int i = 0; i < k; i++)
    {
        cin >> kn[i][0] >> kn[i][1];
    }
    dp[0] = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = T; j >= 0; j--)
        {
            for (int m = 1; m <= kn[i][1]; m++)
            {
                if(j - kn[i][0] * m < 0)
                    break;
                dp[j] += dp[j - kn[i][0] * m];
            }
        }
    }
    cout<<dp[T];
}