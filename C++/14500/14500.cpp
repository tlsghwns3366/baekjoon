#include <iostream>
#include <algorithm>
using namespace std;

int a[5][2][4] = {{{0, 1, 2, 3}, {0, 0, 0, 0}},
                  {{0, 1, 0, 1}, {0, 0, 1, 1}},
                  {{0, 0, 0, 1}, {0, 1, 2, 2}},
                  {{0, 0, 1, 1}, {0, 1, 1, 2}},
                  {{0, 1, 1, 2}, 0, 0, 1, 0}};

int main()
{
    int n, m;
    cin >> n >> m;
    int **nn;
    nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x = 0; x < 5; x++)
            {
                int sum[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                for (int y = 0; y < 4; y++)
                {
                    int tempi1 = i + a[x][0][y];
                    int tempj1 = j + a[x][1][y];

                    int tempi2 = i + (a[x][1][y] * -1);
                    int tempj2 = j + a[x][0][y];

                    int tempi3 = i + (a[x][0][y] * -1);
                    int tempj3 = j + (a[x][1][y] * -1);

                    int tempi4 = i + a[x][1][y];
                    int tempj4 = j + (a[x][0][y] * -1);

                    int tempi5 = i + (a[x][0][y] * -1);
                    int tempj5 = j + a[x][1][y];

                    int tempi6 = i + a[x][0][y];
                    int tempj6 = j + (a[x][1][y] * -1);

                    int tempi7 = i + (a[x][1][y] * -1);
                    int tempj7 = j + (a[x][0][y] * -1);

                    int tempi8 = i + a[x][1][y];
                    int tempj8 = j + a[x][0][y];

                    if (tempi1 < m && tempj1 < n && tempi1 >= 0 && tempj1 >= 0)
                        sum[0] += nn[tempj1][tempi1];
                    if (tempi2 < m && tempj2 < n && tempi2 >= 0 && tempj2 >= 0)
                        sum[1] += nn[tempj2][tempi2];
                    if (tempi3 < m && tempj3 < n && tempi3 >= 0 && tempj3 >= 0)
                        sum[2] += nn[tempj3][tempi3];
                    if (tempi4 < m && tempj4 < n && tempi4 >= 0 && tempj4 >= 0)
                        sum[3] += nn[tempj4][tempi4];
                    if (tempi5 < m && tempj5 < n && tempi5 >= 0 && tempj5 >= 0)
                        sum[4] += nn[tempj5][tempi5];
                    if (tempi6 < m && tempj6 < n && tempi6 >= 0 && tempj6 >= 0)
                        sum[5] += nn[tempj6][tempi6];
                    if (tempi7 < m && tempj7 < n && tempi7 >= 0 && tempj7 >= 0)
                        sum[6] += nn[tempj7][tempi7];
                    if (tempi8 < m && tempj8 < n && tempi8 >= 0 && tempj8 >= 0)
                        sum[7] += nn[tempj8][tempi8];
                }
                for (int y = 0; y < 8; y++)
                {
                    if (ans < sum[y])
                        ans = sum[y];
                }
            }
        }
    }
    cout << ans;
}
