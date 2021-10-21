#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    int d[n + 1];
    fill(d, d + n + 1, INT_MAX);
    vector<pair<int, int>> v[n + 1];
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        v[temp1].push_back(make_pair(temp2, temp3));
    }
    int start, end;
    cin >> start >> end;
    d[start] = 0;
    q.push(make_pair(0, start));
    while (!q.empty())
    {
        int a = -q.top().first;
        int temp = q.top().second;
        q.pop();
        if (d[temp] < a)
            continue;
        for (int i = 0; i < v[temp].size(); i++)
        {
            if (d[v[temp][i].first] > d[temp] + v[temp][i].second)
            {
                d[v[temp][i].first] = d[temp] + v[temp][i].second;
                q.push(make_pair(-d[v[temp][i].first], v[temp][i].first));
            }
        }
    }
    cout << d[end];
}