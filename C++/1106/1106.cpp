#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int c,n;
    vector<vector<int>> v;
    vector<vector<int>> dp(21,vector<int>(1101,987654321));
    int answer = 987654321;
    cin>>c>>n;
    for(int i =0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);

        v.push_back(temp);
    }
    sort(v.rbegin(),v.rend());
    for(int i =1;i<=n;i++)
    {
        dp[i][0] = 0;
        for(int j = 1;j<=1100;j++)
        {
            if(j-v[i-1][1] >= 0)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-v[i-1][1]] + v[i-1][0]);
            }
            else
                dp[i][j] = dp[i-1][j];
            if(j>=c)
            answer = min(dp[i][j],answer);
        }
    }
    cout<<answer;
}