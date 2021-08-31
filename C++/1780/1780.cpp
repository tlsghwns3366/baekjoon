#include <iostream>
using namespace std;
int one = 0;
int zero = 0;
int mi = 0;
void f(int **nn, int n, int x, int y)
{
    int a = nn[x][y];
    bool b = true;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (b && nn[i][j] != a)
            {
                b = false;
                break;
            }
        }
        if (!b)
        {
            break;
        }
    }

    if (b)
    {
        if (a == 1)
            one++;
        else if (a == 0)
            zero++;
        else if (a == -1)
            mi++;
    }
    else
    {
        f(nn, n / 3, x, y);
        f(nn, n / 3, x, y + n / 3);
        f(nn, n / 3, x, y + n / 3 + n / 3);
        f(nn, n / 3, x + n / 3, y);
        f(nn, n / 3, x + n / 3, y + n / 3);
        f(nn, n / 3, x + n / 3, y + n / 3 + n / 3);
        f(nn, n / 3, x + n / 3 + n / 3, y);
        f(nn, n / 3, x + n / 3 + n / 3, y + n / 3);
        f(nn, n / 3, x + n / 3 + n / 3, y + n / 3 + n / 3);
    }
}
int main()
{
    int n;
    cin >> n;
    int **nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    f(nn, n, 0, 0);
    cout << mi << endl;
    cout << zero << endl;
    cout << one << endl;
}