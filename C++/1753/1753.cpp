#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main()
{
    int v, e;
    cin >> v >> e;
    int vv[v + 1];
    fill(vv, vv + v + 1, INT_MAX);
    int k;
    cin >> k;
    vv[k] = 0;
    vector<pair<int, int>> vec[v + 1];
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < e; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        vec[temp1].push_back(make_pair(temp2, temp3));
    }
    q.push(make_pair(0, k));
    while (!q.empty())
    {
        int a, b;
        b = q.top().second;
        q.pop();
        for (int i = 0; i < vec[b].size(); i++)
        {
            int temp = vec[b][i].first;
            if (vv[vec[b][i].first] > vv[b] + vec[b][i].second)
            {
                vv[vec[b][i].first] = vv[b] + vec[b][i].second;
                q.push(make_pair(-vv[vec[b][i].first], vec[b][i].first));
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (vv[i] == INT_MAX)
            cout << "INF"
                 << "\n";
        else
            cout << vv[i] << "\n";
    }
}