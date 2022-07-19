#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int nn[32001];
int ans[32001];
vector<int> v[32001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        nn[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (nn[i] == 0)
            q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int temp = q.front();
        q.pop();
        ans[i] = temp;
        for (int j = 0; j < v[temp].size(); j++)
        {
            nn[v[temp][j]]--;
            if (nn[v[temp][j]] == 0)
                q.push(v[temp][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i]<<" ";
    }
}