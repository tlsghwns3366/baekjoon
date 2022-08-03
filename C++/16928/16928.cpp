#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    vector<int> v[101];
    int ans[101];
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 0; i < 101; i++)
    {
        ans[i] = 987654321;
    }
    queue<int> q;
    q.push(1);
    ans[1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            if (ans[v[x][i]] > ans[x])
            {
                ans[v[x][i]] = ans[x];
                q.push(v[x][i]);
            }
        }
        if (v[x].size() == 0)
        {
            for (int i = 1; i <= 6; i++)
            {
                if (x + i <= 100 && ans[x + i] > ans[x] + 1)
                {
                    ans[x + i] = ans[x] + 1;
                    q.push(x + i);
                }
            }
        }
    }
    cout << ans[100];
}