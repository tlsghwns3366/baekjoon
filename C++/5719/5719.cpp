#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n, m;
int *bb;
int ans;
int st;
int en;
bool **bf;
vector<int> *bn;
vector<pair<int, int>> *vv;
void da(int start)
{
    bb = new int[n];
    bn = new vector<int>[n];
    fill(bb, bb + n, INT_MAX);
    bb[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    while (!q.empty())
    {
        int temp = q.top().second;
        int a = -q.top().first;
        q.pop();
        if (bb[temp] < a)
            continue;
        for (int i = 0; i < vv[temp].size(); i++)
        {
            if (bf[temp][vv[temp][i].first])
                continue;
            if (bb[vv[temp][i].first] > bb[temp] + vv[temp][i].second)
            {
                bb[vv[temp][i].first] = bb[temp] + vv[temp][i].second;
                bn[vv[temp][i].first].clear();
                bn[vv[temp][i].first].push_back(temp);
                q.push(make_pair(-bb[vv[temp][i].first], vv[temp][i].first));
            }
            else if (bb[vv[temp][i].first] == bb[temp] + vv[temp][i].second)
            {
                bn[vv[temp][i].first].push_back(temp);
            }
        }
    }
}

void f(int a)
{
    if (a == st)
        return;
    for (int i = 0; i < bn[a].size(); i++)
    {
        if (!bf[bn[a][i]][a])
        {
            bf[bn[a][i]][a] = true;
            f(bn[a][i]);
        }
    }
}
bool input()
{
    cin >> n >> m;
    if (n == 0 && m == 0)
        return true;
    else
        return false;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (!input())
    {
        cin >> st >> en;
        vv = new vector<pair<int, int>>[n];
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            vv[u].push_back(make_pair(v, p));
        }

        bf = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            bf[i] = new bool[n];
            for (int j = 0; j < n; j++)
            {
                bf[i][j] = false;
            }
        }

        da(st);
        ans = bb[en];
        f(en);
        da(st);

        if (bb[en] == INT_MAX)
        {
            cout << "-1\n";
        }
        else
        {
            cout << bb[en] << "\n";
        }
    }
}