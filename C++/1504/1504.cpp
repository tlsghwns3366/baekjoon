#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int n, e;
int v1, v2;
int sb = false;
int minx(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int f(int a, int b, vector<pair<int, int>> *v)
{
    int vv[n + 1];
    bool nb[n + 1];
    fill(vv, vv + n + 1, INT_MAX);
    fill(nb, nb + n + 1, false);
    vv[a] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, a));
    while (!q.empty())
    {
        int temp = q.top().second;
        q.pop();
        if (!nb[temp])
        {
            for (int i = 0; i < v[temp].size(); i++)
            {
                if (vv[v[temp][i].first] > vv[temp] + v[temp][i].second)
                {
                    vv[v[temp][i].first] = vv[temp] + v[temp][i].second;
                    q.push(make_pair(-vv[v[temp][i].first], v[temp][i].first));
                }
            }
            nb[temp] = true;
        }
    }
    if (vv[b] == INT_MAX)
        sb = true;
    return vv[b];
}
int main()
{
    cin >> n >> e;
    int nn[n + 1];
    vector<pair<int, int>> *v = new vector<pair<int, int>>[n + 1];
    for (int i = 0; i < e; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        v[temp1].push_back(make_pair(temp2, temp3));
        v[temp2].push_back(make_pair(temp1, temp3));
    }
    cin >> v1 >> v2;
    int s = minx(f(1, v1, v) + f(v1, v2, v) + f(v2, n, v), f(1, v2, v) + f(v2, v1, v) + f(v1, n, v));
    if (sb)
        cout << "-1";
    else
        cout << s;
}