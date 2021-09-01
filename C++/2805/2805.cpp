#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *nn = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    long long a = nn[n - 1];
    long long b = 0;
    while (a >= b)
    {
        long long count = 0;
        long long c = (a + b) / 2;
        for (int i = 0; i < n; i++)
        {
            if (nn[i] - c > 0)
                count += nn[i] - c;
        }
        if (count >= m)
        {
            b = c + 1;
        }
        else
        {
            a = c - 1;
        }
    }
    cout << a;
}