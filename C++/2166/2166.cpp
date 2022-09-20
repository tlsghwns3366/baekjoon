#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    pair<double, double> p[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    double ans = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        ans += (((p[i].first - p[1].first) * (p[i + 1].second - p[1].second)) - ((p[i + 1].first - p[1].first) * (p[i].second - p[1].second))) / 2;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}