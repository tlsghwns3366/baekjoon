#include <iostream>
#include <cmath>
using namespace std;
double x, y, c;
double f(double d)
{
    double h1 = sqrt(x * x - d * d);
    double h2 = sqrt(y * y - d * d);

    return (h1 * h2) / (h1 + h2);
}
int main()
{
    cin >> x >> y >> c;
    double a = 0;
    double b = min(x, y);
    double ans = 0;
    while (b - a > 0.000001)
    {
        double d = (a + b) / 2.0;
        if (f(d) >= c)
        {
            a = d;
            ans = d;
        }
        else
            b = d;
    }
    cout.precision(3);
    cout << fixed;
    cout << ans;
}