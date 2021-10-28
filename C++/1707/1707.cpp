#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v, e;
bool f(int a, vector<int> *vec, int *vv)
{
    queue<pair<int, int>> q;
    if (vv[a] == 2)
        vv[a] = !vv[vec[a][0]];
    q.push(make_pair(vv[a], vec[a][0]));
    while (!q.empty())
    {
        bool aa = q.front().first;
        int temp = q.front().second;
        vv[temp] = !aa;
        q.pop();
        for (int i = 0; i < vec[temp].size(); i++)
        {
            if (vv[vec[temp][i]] != vv[temp])
                return false;
            q.push(make_pair(vv[temp], vec[temp][i]));
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> v >> e;
        int *vv = new int[v + 1];
        fill(vv, vv + v + 1, 2);
        vector<int> *vec = new vector<int>[v + 1];
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
        }
        bool s = true;
        for (int i = 1; i <= v; i++)
        {
            if (!vec[i].empty())
            {
                s = f(i, vec, vv);
                if (s == false)
                    break;
            }
        }
        if (s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}