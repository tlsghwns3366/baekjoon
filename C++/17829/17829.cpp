#include <iostream>
#include <algorithm>
using namespace std;
int nn[1024][1024];
int f(int n, int x, int y)
{
    if (n == 1)
        return nn[x][y];
    int a[4];
    a[0] = f(n / 2, x, y);
    a[1] = f(n / 2, x, y + n / 2);
    a[2] = f(n / 2, x + n / 2, y);
    a[3] = f(n / 2, x + n / 2, y + n / 2);
    sort(a, a + 4);
    return a[2];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
        }
    }
    cout << f(n, 0, 0);
}