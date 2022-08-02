#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int time[10001];
int count[10001];
int dp[10001];
vector<int> v[10001];
int main()
{
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> time[i] >> count[i];
        for (int j = 0; j < count[i]; j++)
        {
            int temp;
            cin >> temp;
            v[temp].push_back(i);
            v[i].push_back(temp);
        }
        if(count[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int temp = 0;
        for (int i = 0; i < v[x].size(); i++)
        {
            if (temp < dp[v[x][i]])
                temp = dp[v[x][i]];
            count[v[x][i]]--;
            if (count[v[x][i]] == 0 && dp[x] == 0)
            {
                q.push(v[x][i]);
            }
        }
        dp[x] += time[x];
        dp[x] += temp;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << ans;
}