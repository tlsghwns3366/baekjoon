#include <iostream>
#include <vector>
using namespace std;
bool *b;
void f(vector<int> *v, int a)
{
    b[a] = true;
    if (!v[a].empty())
    {
        for (int i = 0; i < v[a].size(); i++)
        {
            if (!b[v[a][i]])
                f(v, v[a][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    b = new bool[n + 1];
    fill(b, b + n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int tempn;
        int tempm;
        cin >> tempn >> tempm;
        v[tempn].push_back(tempm);
        v[tempm].push_back(tempn);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!b[i])
        {
            ans++;
            f(v, i);
        }
    }
    cout << ans;
}