#include <iostream>
using namespace std;
int n;
int p[9] = {4, 0, 0, 0, 0, 0, 0, 0, 0};
int dx[8] = {1, 2, 3, 5, 6, 7, 8, 9};
bool db[8];
int nn[50][9];
int ans = 0;
void f(int a)
{
    if (a == 9)
    {
        int out = 0;
        bool base[4];
        int num = 1;
        int sum = 0;
        for (int t = 0; t < n; t++)
        {
            fill(base, base + 4, false);
            while (out < 3)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (p[i] == num)
                    {
                        num++;
                        if (nn[t][i] == 0)
                        {
                            out++;
                            if (num == 10)
                                num = 1;
                            break;
                        }
                        else if (nn[t][i] == 1)
                        {
                            for (int j = 3; j > 0; j--)
                            {
                                if (base[j])
                                {
                                    if (j == 3)
                                    {
                                        sum++;
                                        base[j] = false;
                                    }
                                    else
                                    {
                                        base[j + 1] = true;
                                        base[j] = false;
                                    }
                                }
                            }
                            base[1] = true;
                        }
                        else if (nn[t][i] == 2)
                        {
                            for (int j = 3; j > 0; j--)
                            {
                                if (base[j])
                                {
                                    if (j == 3 || j == 2)
                                    {
                                        sum++;
                                        base[j] = false;
                                    }
                                    else
                                    {
                                        base[j + 2] = true;
                                        base[j] = false;
                                    }
                                }
                            }
                            base[2] = true;
                        }
                        else if (nn[t][i] == 3)
                        {
                            for (int j = 3; j > 0; j--)
                            {
                                if (base[j])
                                {
                                    sum++;
                                    base[j] = false;
                                }
                            }
                            base[3] = true;
                        }
                        else if (nn[t][i] == 4)
                        {
                            for (int j = 3; j > 0; j--)
                            {
                                if (base[j])
                                {
                                    sum++;
                                    base[j] = false;
                                }
                            }
                            sum++;
                        }
                        if (num == 10)
                            num = 1;
                        if (out == 3)
                            break;
                    }
                }
            }
            out = 0;
        }
        if (ans < sum)
            ans = sum;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (!db[i])
        {
            db[i] = true;
            p[a] = dx[i];
            f(a + 1);
            db[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> nn[i][j];
        }
    }
    f(1);
    cout << ans;
}