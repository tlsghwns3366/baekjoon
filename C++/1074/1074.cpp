#include <iostream>
using namespace std;
int f(int n, int r, int c)
{
    int n2 = n / 2;
    if (n == 2)
    {
        if (r < n2 && c < n2)
        {
            return 1;
        }
        else if (r < n2 && c >= n2)
        {
            return 2;
        }
        else if (r >= n2 && c < n2)
        {
            return 3;
        }
        else if (r >= n2 && c >= n2)
        {
            return 4;
        }
    }
    else
    {
        if (r < n2 && c < n2)
        {
            return f(n2, r, c);
        }
        else if (r < n2 && c >= n2)
        {
            return f(n2, r, c - n2) + (n2 * n2);
        }
        else if (r >= n2 && c < n2)
        {
            return f(n2, r - n2, c) + (n2 * n2) * 2;
        }
        else if (r >= n2 && c >= n2)
        {
            return f(n2, r - n2, c - n2) + (n2 * n2) * 3;
        }
    }
}
int main()
{
    int n, r, c;
    cin >> n >> r >> c;

    int a = 1;
    for (int i = 0; i < n; i++)
    {
        a *= 2;
    }
    cout << f(a, r, c) - 1;
}