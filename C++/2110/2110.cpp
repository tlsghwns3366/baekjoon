#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, c;
    cin >> n >> c;
    int *nn = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    long long a = nn[n - 1];
    long long b = 0;
    int max = 0;
    while (a >= b)
    {
        long long count = 1;
        long long m = (a + b) / 2;
        long long temp = nn[0];
        for (int i = 1; i < n; i++)
        {
            if (nn[i] - temp >= m)
            {
                temp = nn[i];
                count++;
                if (count == c)
                    break;
            }
        }
        if (count >= c)
        {
            b = m + 1;
        }
        else
        {
            a = m - 1;
        }
        if (count == c)
        {
            if (max < m)
                max = m;
        }
    }
    cout << max;
}