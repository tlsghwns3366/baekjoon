#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, x2, x3;
    double y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    double d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double d2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double d3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double m1 = 1987654321;
    double m2 = 1987654321;
    if (x1 != x2)
        m1 = abs(y2 - y1) / abs(x2 - x1);
    if (x2 != x3)
        m2 = abs(y3 - y2) / abs(x3 - x2);
    if (m1 == m2)
        cout << -1;
    else
    {
        cout << fixed;
        cout.precision(16);
        cout << max(max((2 * (d1 + d2)), 2 * (d3 + d1)), (2 * (d2 + d3))) - min(min((2 * (d1 + d2)), 2 * (d3 + d1)), (2 * (d2 + d3)));
    }
}