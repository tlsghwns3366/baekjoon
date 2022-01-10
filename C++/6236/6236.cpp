#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int a = 0;
    int b = 10000 * 100000;
    int ans = 0;
    while (a <= b)
    {
        int c = (a + b) / 2;
        int temp = c;
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (nn[i] > c)
            {
                count = m + 1;
                break;
            }
            if (temp - nn[i] < 0)
            {
                temp = c;
                count++;
            }
            temp -= nn[i];
        }
        if (count <= m)
        {
            ans = c;
            b = c - 1;
        }
        else
        {
            a = c + 1;
        }
    }
    cout << ans;
}