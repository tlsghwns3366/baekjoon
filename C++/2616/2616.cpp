#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,k;
    cin >> n;
    vector<int> v(1);
    vector<vector<int>> dp(4,vector<int>(50001));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.push_back(v[i-1]+a);
    }
    cin >> k;
    for(int i =1;i<=3;i++)
    {
        for(int j = i*k;j<=n;j++)
        {
            dp[i][j] = max(dp[i][j-1],dp[i-1][j-k] + (v[j] - v[j-k]));
        }
    }
    cout<<dp[3][n];
}