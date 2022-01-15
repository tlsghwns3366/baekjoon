#include <iostream>
using namespace std;
int main()
{
    int w, h;
    cin >> w >> h;
    int p, q;
    cin >> p >> q;
    int t;
    cin >> t;
    p = (p + t) % (2 * w);
    q = (q + t) % (2 * h);
    if (p > w)
        p = 2 * w - p;
    if (q > h)
        q = 2 * h - q;
    cout << p << " " << q;
}