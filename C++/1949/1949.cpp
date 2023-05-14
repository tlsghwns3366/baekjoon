#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[10001][2];
vector<int> v[10001];
int town[10001];
bool b[10001];
int n;
void f(int a)
{
    b[a] = true;
    dp[a][0] = 0;
    dp[a][1] = town[a];
    for (int i = 0; i < v[a].size(); i++)
    {
        if (!b[v[a][i]])
        {
            f(v[a][i]);
            dp[a][0] += max(dp[v[a][i]][1], dp[v[a][i]][0]);
            dp[a][1] += dp[v[a][i]][0];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> town[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    f(1);
    cout << max(dp[1][0], dp[1][1]);
}