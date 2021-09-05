#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int m;
    cin >> m;
    sort(nn, nn + n);
    int a = nn[n - 1];
    int b = 0;
    int max = 0;
    while (a >= b)
    {
        int c = (a + b) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (c >= nn[i])
                count += nn[i];
            else
                count += c;
        }
        if (count > m)
            a = c - 1;
        else
        {
            b = c + 1;
            if (max < c)
                max = c;
        }
    }
    cout << max;
}