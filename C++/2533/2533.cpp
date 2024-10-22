#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(1000001);
vector<vector<int>> dp(1000001, vector<int>(2));
vector<bool> dpb(1000001);
void dfs(int a)
{
    int value = 1;
    for (int i = 0; i < v[a].size(); i++)
    {
        if (!dpb[v[a][i]])
        {
            dpb[v[a][i]] = true;
            dfs(v[a][i]);
            dp[a][1] += dp[v[a][i]][0];
            value += min(dp[v[a][i]][0], dp[v[a][i]][1]);
        }
    }
    dp[a][0] = value;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dpb[1] = true;
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}