#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t[100001];
vector<int> v[100001];
int tcount = 1;
void dfs(int r)
{
    t[r] = tcount;
    tcount++;
    sort(v[r].begin(), v[r].end());
    for (int i = 0; i < v[r].size(); i++)
    {
        if (!t[v[r][i]])
            dfs(v[r][i]);
    }
}
int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << "\n";
    }
}