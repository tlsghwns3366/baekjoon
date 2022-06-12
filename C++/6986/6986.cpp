#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double nn[100001];
int main()
{
    int n, k;
    cin >> n >> k;
    double ans1 = 0;
    double ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    for (int i = k; i < n - k; i++)
    {
        ans1 += nn[i];
        ans2 += nn[i];
    }
    ans1 /= n - 2 * k + 0;
    ans2 += nn[k] * k + nn[n - k - 1] * k;
    ans2 /= n + 0;
    printf("%.2lf\n", ans1 + 0.00000001);
    printf("%.2lf\n", ans2 + 0.00000001);
}