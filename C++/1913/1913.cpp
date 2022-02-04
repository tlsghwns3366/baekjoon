#include <iostream>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, f;
    cin >> n >> f;
    int nn[n + 1][n + 1];
    fill(&nn[0][0], &nn[n][n], 0);
    int tx = 0;
    int ty = 0;
    int i = n * n;
    int z = 0;
    int ans = 0;
    int ansx = 0;
    int ansy = 0;
    nn[0][0] = i;
    i--;
    while (i > 0)
    {
        if (tx + dx[z] < n && tx + dx[z] >= 0 && ty + dy[z] < n && ty + dy[z] >= 0 && nn[tx + dx[z]][ty + dy[z]] == 0)
        {
            tx += dx[z];
            ty += dy[z];
            nn[tx][ty] = i;
            if (i == f)
            {
                ansx = tx;
                ansy = ty;
            }
            i--;
        }
        else
        {
            z++;
            if (z > 4)
                z = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nn[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ansx + 1 << " " << ansy + 1;
}