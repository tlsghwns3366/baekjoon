#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x[3];
    double y[3];
    double z[3];
    cout << fixed;
    cout.precision(6);
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    double dx = x[1] - x[0];
    double dy = y[1] - y[0];
    double dz = z[1] - z[0];
    double t = ((-x[0] + x[2]) * dx + (-y[0] + y[2]) * dy + (-z[0] + z[2]) * dz) / (dx * dx + dy * dy + dz * dz);
    double ansx = dx * t + x[0];
    double ansy = dy * t + y[0];
    double ansz = dz * t + z[0];
    double ans;
    if (((x[1] - x[0]) * (x[2] - x[0]) + (y[1] - y[0]) * (y[2] - y[0]) + (z[1] - z[0]) * (z[2] - z[0])) * ((x[1] - x[0]) * (x[2] - x[1]) + (y[1] - y[0]) * (y[2] - y[1]) + (z[1] - z[0]) * (z[2] - z[1])) <= 0)
        ans = sqrt((ansx - x[2]) * (ansx - x[2]) + (ansy - y[2]) * (ansy - y[2]) + (ansz - z[2]) * (ansz - z[2]));
    else
        ans = min(sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]) + (z[0] - z[2]) * (z[0] - z[2])), sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]) + (z[1] - z[2]) * (z[1] - z[2])));
    cout << ans;
}