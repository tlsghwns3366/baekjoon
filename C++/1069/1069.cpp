#include <iostream>
#include <cmath>
using namespace std;
double min(double a, double b)
{
    return a < b ? a : b;
}
int main()
{
    double x, y, d, t;
    cin >> x >> y >> d >> t;
    double di = sqrt(x * x + y * y);
    double ans = di;
    int jump = di / d;
    di -= jump * d;
    if (jump == 0)
        ans = min(ans, min(t * 2, d - di + t));
    else
        ans = min(ans,min(jump*t+di,(jump+1)*t));
    cout<<fixed;
    cout.precision(9);
    cout<<ans;
}