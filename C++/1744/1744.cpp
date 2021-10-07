#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int cmp2(int a, int b)
{
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }

    sort(nn, nn + n, cmp);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (nn[i] <= 0)
        {
            sort(nn + i, nn + n, cmp2);
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (nn[i - 1] * nn[i] > nn[i - 1] + nn[i])
        {
            s += nn[i - 1] * nn[i];
            i++;
        }
        else
        {
            s += nn[i - 1];
        }
        if (i == n - 1)
            s += nn[n - 1];
    }
    if (n == 1)
        s += nn[n - 1];
    cout << s;
}