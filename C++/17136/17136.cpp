#include <iostream>
using namespace std;
int nn[10][10];
int cp[5] = {5, 5, 5, 5, 5};
int count = 0;
int ans = 987654321;
void f(int anscount)
{
    if (anscount == count)
    {
        int temp = 0;
        for (int i = 0; i < 5; i++)
        {
            temp += 5 - cp[i];
        }
        if (ans > temp)
            ans = temp;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (nn[i][j] == 1)
            {
                for (int q = 4; q >= 0; q--)
                {
                    bool temp = true;
                    if (i + q >= 10 || j + q >= 10 || cp[q] - 1 < 0)
                        continue;
                    for (int x = i; x <= i + q; x++)
                    {
                        for (int y = j; y <= j + q; y++)
                        {
                            if (nn[x][y] == 0)
                                temp = false;
                        }
                    }
                    if (temp)
                    {
                        int tempcount = 0;
                        cp[q]--;
                        for (int x = i; x <= i + q; x++)
                        {
                            for (int y = j; y <= j + q; y++)
                            {
                                nn[x][y] = 0;
                            }
                        }
                        f(anscount + (q + 1) * (q + 1));
                        cp[q]++;
                        for (int x = i; x <= i + q; x++)
                        {
                            for (int y = j; y <= j + q; y++)
                            {
                                nn[x][y] = 1;
                            }
                        }
                    }
                }
                return;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 1)
                count++;
        }
    }
    f(0);
    if (ans == 987654321)
        cout << "-1";
    else
        cout << ans;
}