#include <iostream>
using namespace std;
int n, m, l;
int nn[51];
int main()
{
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int a = 1;
    int b = 1000;
    while (a <= b)
    {
        int c = (a + b) / 2;
        bool temp[1001];
        fill(temp, temp + 1001, false);
        for (int i = 0; i < n; i++)
        {
            temp[nn[i]] = true;
        }
        int d = 0;
        int tm = 0;
        for (int i = 0; i < l; i++)
        {
            if (temp[i])
            {
                d = i;
            }
            else if (i - d == c)
            {
                d = i;
                temp[i] = true;
                tm++;
            }
        }
        if (tm <= m)
        {
            b = c - 1;
        }
        else
        {
            a = c + 1;
        }
    }
    cout << a;
}