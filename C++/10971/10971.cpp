#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    int ans = INT_MAX;
    do
    {
        bool f = false;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nn[v[i]][v[i + 1]] == 0)
                f = true;
            else
            {
                sum += nn[v[i]][v[i + 1]];
            }
        }
        if (!f && nn[v[n - 1]][v[0]] != 0)
        {
            sum += nn[v[n - 1]][v[0]];
            ans = min(sum, ans);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}