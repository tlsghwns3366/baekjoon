#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int nn[2][n];
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < n)
                cin >> nn[0][j];
            else
                cin >> nn[1][j - n];
        }

        int a[n];
        int b[n];
        fill(a, a + n, 0);
        fill(b, b + n, 0);
        a[0] = nn[0][0];
        b[0] = nn[1][0];
        if (n > 1)
        {
            a[1] = b[0] + nn[0][1];
            b[1] = a[0] + nn[1][1];
        }
        for (int j = 2; j < n; j++)
        {
            a[j] = max(b[j - 1] + nn[0][j], b[j - 2] + nn[0][j]);
            b[j] = max(a[j - 1] + nn[1][j], a[j - 2] + nn[1][j]);
        }
        cout << max(a[n - 1], b[n - 1]) << "\n";
    }
}