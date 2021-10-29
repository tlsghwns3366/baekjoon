#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nm[n + 1];
    fill(nm, nm + n + 1, 0);
    vector<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i].empty())
        {
            queue<int> q;
            bool bb[n + 1];
            int x = 0;
            fill(bb, bb + n + 1, false);
            q.push(i);
            bb[i] = true;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                for (int j = 0; j < v[temp].size(); j++)
                {
                    if (!bb[v[temp][j]])
                    {
                        x++;
                        bb[v[temp][j]] = true;
                        q.push(v[temp][j]);
                    }
                }
            }
            if (ans < x)
                ans = x;
            nm[i] = x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (nm[i] == ans)
            cout << i << " ";
    }
}