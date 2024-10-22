#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> dp(1001,987654321);
    vector<int> v;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    dp[0] = 0;
    for(int i =1;i<=n;i++)
    {
        for(int j =0;j+i<=1001;j++)
        {
            dp[j+i] = min(dp[j+i],dp[j] + v[i-1]);
        }
    }
    cout<<dp[n];

}