#include <iostream>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int rc[1001][50][50] = {
    0,
};
int main()
{
    int r, c, t;
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> rc[0][i][j];
        }
    }
    for (int q = 0; q < t; q++)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (rc[q][i][j] >= 5)
                {
                    int ctemp = 0;
                    int num = rc[q][i][j] / 5;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < r && y >= 0 && y < c)
                        {
                            if (rc[q][x][y] != -1)
                            {
                                ctemp++;
                                rc[q + 1][x][y] += num;
                            }
                        }
                    }
                    rc[q + 1][i][j] += rc[q][i][j] - (num * ctemp);
                }
                else
                {
                    rc[q + 1][i][j] += rc[q][i][j];
                }
            }
        }
        bool ud = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (rc[q + 1][i][j] == -1)
                {
                    int temp = 0;
                    int x = i + dx[0];
                    int y = j + dy[0];
                    int a = 0;
                    while (rc[q + 1][x][y] != -1)
                    {
                        int temp2 = rc[q + 1][x][y];
                        rc[q + 1][x][y] = temp;
                        temp = temp2;
                        if ((x == i && y == c - 1) || (x == 0 && y == c - 1) || (x == r - 1 && y == c - 1) || (x == 0 && y == 0) || (x == r - 1 && y == 0))
                            a++;
                        if (!ud)
                        {
                            x += dx[a];
                            y += dy[a];
                        }
                        else
                        {
                            x += (-dx[a]);
                            y += dy[a];
                        }
                    }
                    ud = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[t][i][j] != -1)
                ans += rc[t][i][j];
        }
    }
    cout << ans;
}