#include <iostream>
using namespace std;
struct DICE
{
    int x, y;
    int ans[6] = {
        0,
    };
};
int main()
{
    int n, m, k;
    DICE d;
    cin >> n >> m >> d.x >> d.y >> k;
    int nm[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }

    for (int t = 0; t < k; t++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            if (d.y + 1 < m)
            {
                d.y++;
                int temp = d.ans[0];
                d.ans[0] = d.ans[3];
                d.ans[3] = d.ans[5];
                d.ans[5] = d.ans[2];
                d.ans[2] = temp;

                if (nm[d.x][d.y] == 0)
                    nm[d.x][d.y] = d.ans[5];
                else
                {
                    d.ans[5] = nm[d.x][d.y];
                    nm[d.x][d.y] = 0;
                }

                cout << d.ans[0] << "\n";
            }
        }
        else if (a == 2)
        {
            if (d.y - 1 >= 0)
            {
                d.y--;
                int temp = d.ans[0];
                d.ans[0] = d.ans[2];
                d.ans[2] = d.ans[5];
                d.ans[5] = d.ans[3];
                d.ans[3] = temp;

                if (nm[d.x][d.y] == 0)
                    nm[d.x][d.y] = d.ans[5];
                else
                {
                    d.ans[5] = nm[d.x][d.y];
                    nm[d.x][d.y] = 0;
                }

                cout << d.ans[0] << "\n";
            }
        }
        else if (a == 3)
        {
            if (d.x - 1 >= 0)
            {
                d.x--;
                int temp = d.ans[0];
                d.ans[0] = d.ans[4];
                d.ans[4] = d.ans[5];
                d.ans[5] = d.ans[1];
                d.ans[1] = temp;

                if (nm[d.x][d.y] == 0)
                    nm[d.x][d.y] = d.ans[5];
                else
                {
                    d.ans[5] = nm[d.x][d.y];
                    nm[d.x][d.y] = 0;
                }

                cout << d.ans[0] << "\n";
            }
        }
        else if (a == 4)
        {
            if (d.x + 1 < n)
            {
                d.x++;
                int temp = d.ans[0];
                d.ans[0] = d.ans[1];
                d.ans[1] = d.ans[5];
                d.ans[5] = d.ans[4];
                d.ans[4] = temp;

                if (nm[d.x][d.y] == 0)
                    nm[d.x][d.y] = d.ans[5];
                else
                {
                    d.ans[5] = nm[d.x][d.y];
                    nm[d.x][d.y] = 0;
                }

                cout << d.ans[0] << "\n";
            }
        }
    }
}