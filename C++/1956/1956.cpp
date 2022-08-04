#include <iostream>
using namespace std;
int ve[401][401];
int main()
{
    int v, e;
    cin >> v >> e;
    fill(&ve[0][0], &ve[v][v + 1], 987654321);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ve[a][b] = ve[a][b] > c ? c : ve[a][b];
    }
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            for (int k = 1; k <= v; k++)
            {
                if (ve[j][k] > ve[j][i] + ve[i][k])
                    ve[j][k] = ve[j][i] + ve[i][k];
            }
        }
    }
    int ans = 987654321;
    for (int i = 1; i <= v; i++)
    {
        if (ve[i][i] < ans)
            ans = ve[i][i];
    }
    if (ans == 987654321)
        cout << -1;
    else
        cout << ans;
}