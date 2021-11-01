#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, int>> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        v[temp1].push_back(make_pair(temp2, temp3));
    }
    int nn[n + 1][n + 1];
    fill(&nn[0][0], &nn[n][n + 1], INT_MAX);
    for (int i = 1; i <= n; i++)
    {
        nn[i][i] = 0;
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, i));
        while (!q.empty())
        {
            int temp = -q.top().first;
            int a = q.top().second;
            q.pop();
            for (int j = 0; j < v[a].size(); j++)
            {
                if (nn[i][v[a][j].first] > nn[i][a] + v[a][j].second)
                {
                    nn[i][v[a][j].first] = nn[i][a] + v[a][j].second;
                    q.push(make_pair(-v[a][j].second, v[a][j].first));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = nn[i][x] + nn[x][i];
        if (ans < temp)
            ans = temp;
    }
    cout << ans;
}