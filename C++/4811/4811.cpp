#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<long long>> dp(31,vector<long long>(31,0));
    for(int i =1;i<=30;i++)
    {
        dp[i][0] = 1;
        for(int j =1;j<=30;j++)
        {
            if(i<j)
                continue;
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout<<dp[n][n]<<endl;
    }
}