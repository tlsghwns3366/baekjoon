#include <iostream>
using namespace std;
int main()
{
    int n, m;
    int *nn = new int[n];
    int sum = 0;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        sum += nn[i];
    }
    int a = 0;
    int b = sum;
    ans = sum;
    while (a <= b)
    {
        int c = (a + b) / 2;
        int cnt = 1;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (nn[i] > c)
            {
                cnt = n + 1;
                break;
            }
            s += nn[i];
            if (s > c)
            {
                cnt++;
                s = nn[i];
            }
        }
        if (cnt > m)
        {
            a = c + 1;
        }
        else
        {
            b = c - 1;
            if (ans > c)
                ans = c;
        }
    }
    cout << ans;
}