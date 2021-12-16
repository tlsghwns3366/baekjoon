#include <iostream>
using namespace std;
int main()
{
    int nn[5][5];
    int a[5];
    int b[5];
    int x = 0;
    int y = 0;
    fill(a, a + 5, 0);
    fill(b, b + 5, 0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> nn[i][j];
        }
    }
    int ans = 0;
    int aa = -1;
    for (int q = 0; q < 25; q++)
    {
        int temp;
        cin >> temp;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (nn[i][j] == temp)
                {
                    a[i]++;
                    b[j]++;
                    if (i - j == 0)
                        y++;
                    if (i + j == 4)
                        x++;
                    if (a[i] == 5)
                    {
                        ans++;
                        a[i]++;
                    }
                    if (b[j] == 5)
                    {
                        ans++;
                        b[j]++;
                    }
                    if (x == 5)
                    {
                        ans++;
                        x++;
                    }
                    if (y == 5)
                    {
                        ans++;
                        y++;
                    }
                }
            }
        }
        if (ans >= 3)
        {
            aa = q + 1;
            break;
        }
    }
    cout << aa;
}