#include <iostream>
#include <string>
using namespace std;
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
        cout << a;
    }
    else
    {
        cout << "(";
        f(nn, n / 2, x, y);
        f(nn, n / 2, x, y + n / 2);
        f(nn, n / 2, x + n / 2, y);
        f(nn, n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int **nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        string a;
        cin >> a;

        for (int j = 0; j < n; j++)
        {
            nn[i][j] = a[j] - '0';
        }
    }
    f(nn, n, 0, 0);
}