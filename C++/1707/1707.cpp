#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v, e;
bool f(int a, vector<int> *vec, int *vv)
{
    queue<int> q;
    vv[a] = 1;
    q.push(a);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < vec[temp].size(); i++)
        {
            if (vv[vec[temp][i]] == 2)
            {
                vv[vec[temp][i]] = !vv[temp];
                q.push(vec[temp][i]);
            }
            else
            {
                if (vv[temp] == vv[vec[temp][i]])
                    return false;
            }
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
            vec[b].push_back(a);
        }
        bool s = true;
        for (int i = 1; i <= v; i++)
        {
            if (vv[i] == 2)
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