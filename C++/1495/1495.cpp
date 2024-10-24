#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int  n,s,m;
    cin>>n>>s>>m;
    vector<int> v(n+1);
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    dp[0][s] = 1;
    for(int i =1;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(dp[i-1][j] == 1)
            {
                if(j+v[i-1] <= m)
                    dp[i][j+v[i-1]] = 1;
                if(j-v[i-1] >= 0)
                    dp[i][j-v[i-1]] = 1;
            }
        }
    }
    int answer = -1;
    for(int i =0;i<=m;i++)
    {
        if(dp[n][i] == 1)
            answer = max(answer,i);
    }
    cout<<answer;
}