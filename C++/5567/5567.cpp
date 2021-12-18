#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    bool b[n + 1];
    fill(b, b + n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    b[1] = true;
    for (int i = 0; i < v[1].size(); i++)
    {
        b[v[1][i]] = true;
        for (int j = 0; j < v[v[1][i]].size(); j++)
        {
            b[v[v[1][i]][j]] = true;
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (b[i])
        {
            ans++;
        }
    }
    cout << ans;
}