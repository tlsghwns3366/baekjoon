#include <iostream>
#include <algorithm>

using namespace std;

int chleo(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return chleo(b, a % b);
}
void dir(int a)
{
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            cout << i << " ";
    }
    cout << a;
}
int main()
{
    int n;
    cin >> n;
    int *m = new int[n]{0};
    int *ma = new int[100]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    sort(m, m + n);
    for (int i = 1; i < n; i++)
    {
        ma[i - 1] = m[i] - m[i - 1];
    }
    int chl = 0;
    if (n == 2)
    {
        chl = abs(m[0] - m[1]);
    }
    else
    {
        for (int i = 1; i < 100; i++)
        {
            if (ma[i - 1] != 0 && ma[i] != 0)
            {
                if (chl == 0)
                    chl = chleo(ma[i - 1], ma[i]);
                else
                    chl = chleo(ma[i - 1], chl);
            }
        }
    }
    dir(chl);
}