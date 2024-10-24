#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<long long>> dp(66,vector<long long>(10));
    for(int i =0;i<=9;i++)
    {
        dp[1][i] = 1;
    }
    for(int i =2;i<=65;i++)
    {
        for(int j = 0;j<10;j++)
        {
            for(int k =j;k<10;k++)
            {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        cout<<dp[n+1][0]<<endl;
    }
}