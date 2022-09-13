#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int student[401][4];
int nn[21][21];
int main()
{
    cin >> n;
    for (int q = 1; q <= n * n; q++)
    {
        int temp;
        cin >> temp;
        cin >> student[temp][0] >> student[temp][1] >> student[temp][2] >> student[temp][3];
        int x = 0;
        int y = 0;
        int like = -1;
        int b = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nn[i][j] == 0)
                {
                    int likecount = 0;
                    int bcount = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        if (i + dx[k] <= n && i + dx[k] > 0 && j + dy[k] <= n && j + dy[k] > 0)
                        {
                            for (int l = 0; l < 4; l++)
                            {
                                if (nn[i + dx[k]][j + dy[k]] == student[temp][l])
                                    likecount++;
                            }
                            if (nn[i + dx[k]][j + dy[k]] == 0)
                                bcount++;
                        }
                    }
                    if (like < likecount)
                    {
                        like = likecount;
                        b = bcount;
                        x = i;
                        y = j;
                    }
                    if (like == likecount && b < bcount)
                    {
                        b = bcount;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        nn[x][y] = temp;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp = 0;
            for (int k = 0; k < 4; k++)
            {
                if (i + dx[k] <= n && i + dx[k] > 0 && j + dy[k] <= n && j + dy[k] > 0)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (nn[i + dx[k]][j + dy[k]] == student[nn[i][j]][l])
                            temp++;
                    }
                }
            }
            if (temp == 4)
                ans += 1000;
            else if (temp == 3)
                ans += 100;
            else if (temp == 2)
                ans += 10;
            else if (temp == 1)
                ans += 1;
        }
    }
    cout << ans;
}