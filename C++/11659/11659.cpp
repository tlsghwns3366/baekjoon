#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }

    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + nn[i];
    }
    for (int x = 0; x < m; x++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }
}