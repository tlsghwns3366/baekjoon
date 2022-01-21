#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double nn[n];
    double dd[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        dd[i] = 0;
    }
    dd[0] = nn[0];
    double ans = dd[0];
    for (int i = 1; i < n; i++)
    {
        if (dd[i - 1] * nn[i] < nn[i - 1] * nn[i])
            dd[i] = nn[i - 1] * nn[i];
        else
            dd[i] = dd[i - 1] * nn[i];
        if (dd[i] < nn[i])
            dd[i] = nn[i];

        if (dd[i] > ans)
            ans = dd[i];
    }
    printf("%.3lf", ans);
}