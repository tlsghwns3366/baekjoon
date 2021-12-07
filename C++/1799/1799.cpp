#include <iostream>
using namespace std;
int n;
int **nn;
bool *b1;
bool *b2;
int ans;
void f(int a, int c)
{
    if (c > ans)
        ans = c;
    if (a > n * 2 - 1)
        return;
    int x, y;
    if (a < n)
    {
        x = 0;
        y = a;
    }
    else
    {
        x = a - (n - 1);
        y = n - 1;
    }
    bool temp = false;
    while (y >= 0 && x < n)
    {
        if (nn[x][y] == 1 && !b1[x + y] && !b2[(n - 1) - (x - y)])
        {
            b1[x + y] = true;
            b2[(n - 1) - (x - y)] = true;
            f(a + 2, c + 1);
            temp = true;
            b1[x + y] = false;
            b2[(n - 1) - (x - y)] = false;
        }
        y--;
        x++;
    }
    if (!temp)
        f(a + 2, c);
}
int main()
{
    cin >> n;
    nn = new int *[n];
    b1 = new bool[n * 2 - 1];
    b2 = new bool[n * 2 - 1];
    ans = 0;
    fill(b1, b1 + (n * 2), false);
    fill(b2, b2 + (n * 2), false);
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    f(0, 0);
    int temp = ans;
    ans = 0;
    f(1, 0);
    cout << temp + ans;
}