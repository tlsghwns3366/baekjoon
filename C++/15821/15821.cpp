#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    double d[n];
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        double temp = 0;
        for (int j = 0; j < p; j++)
        {
            double x, y;
            cin >> x >> y;
            temp = temp < x * x + y * y ? x * x + y * y : temp;
        }
        d[i] = temp;
    }
    sort(d, d + n);
    cout << fixed;
    cout.precision(2);
    cout << d[k - 1];
}