#include <iostream>
using namespace std;
int **nn;
int **dp;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    nn = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        nn[i] = new int[n + 1]{};
        for (int j = 1; j <= n; j++)
        {
            cin >> nn[i][j];
            nn[i][j] += nn[i][j - 1];
        }
    }
    for (int q = 0; q < m; q++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;

        for (int i = x1; i <= x2; i++)
        {
            ans += nn[i][y2] - nn[i][y1 - 1];
        }
        cout << ans << "\n";
    }
}