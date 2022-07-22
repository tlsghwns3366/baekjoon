#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int nn[501];
int dp[501];
vector<int> v[501];
int vcount[501];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        while (true)
        {
            int temp;
            cin >> temp;
            if (temp == -1)
                break;
            if (nn[i] == 0)
                nn[i] = temp;
            else
            {
                v[temp].push_back(i);
                v[i].push_back(temp);
                vcount[i]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i < 501; i++)
    {
        if (vcount[i] == 0)
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
            vcount[v[x][i]]--;
            if (vcount[v[x][i]] == 0 && dp[x] == 0)
                q.push(v[x][i]);
        }
        dp[x] += nn[x];
        dp[x] += temp;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << "\n";
    }
}