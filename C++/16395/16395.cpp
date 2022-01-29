#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nn[n + 2][n + 2];
    fill(&nn[0][0], &nn[n + 1][n + 1], 0);
    for (int i = 0; i <= n; i++)
    {
        nn[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            nn[i][j] = nn[i - 1][j - 1] + nn[i - 1][j];
        }
    }
    cout << nn[n - 1][k - 1];
}