#include <iostream>
#include <cmath>
using namespace std;
char star[6561][6561];
void f(int n, int x, int y, bool b)
{
    int a = n / 3;
    if (n == 1)
    {
        for (int i = x; i < x + n; i++)
        {
            for (int j = y; j < y + n; j++)
            {
                if (!b)
                    star[i][j] = '*';
                else
                    star[i][j] = ' ';
            }
        }
        return;
    }
    if (b)
        f(a, x + 1 * a, y + 1 * a, b);
    else
        f(a, x + 1 * a, y + 1 * a, !b);
    f(a, x, y, b);
    f(a, x, y + 1 * a, b);
    f(a, x, y + 2 * a, b);
    f(a, x + 1 * a, y, b);
    f(a, x + 1 * a, y + 2 * a, b);
    f(a, x + 2 * a, y, b);
    f(a, x + 2 * a, y + 1 * a, b);
    f(a, x + 2 * a, y + 2 * a, b);
}
int main()
{
    int n;
    cin >> n;
    f(n, 0, 0, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << star[i][j];
        }
        cout << endl;
    }
}