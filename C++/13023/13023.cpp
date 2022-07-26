#include <iostream>
#include <vector>
using namespace std;
vector<int> v[2000];
bool nb[2000];
int ans = 0;
void f(int a, int b)
{
    if (b == 4)
    {
        ans = 1;
        return;
    }
    for (int i = 0; i < v[a].size(); i++)
    {
        if (!nb[v[a][i]])
        {
            nb[v[a][i]] = true;
            f(v[a][i], b + 1);
            nb[v[a][i]] = false;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        nb[i] = true;
        f(i, 0);
        nb[i] = false;
        if (ans == 1)
            break;
    }
    cout << ans;
}