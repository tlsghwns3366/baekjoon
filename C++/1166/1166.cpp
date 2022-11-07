#include <iostream>
using namespace std;
int main()
{
    long long int n, l, w, h;
    cin >> n >> l >> w >> h;
    double a = 0;
    double b = 1000000000;
    for (int i = 0; i < 100; i++)
    {
        double c = (a + b) / 2.0;
        long long int temp = (long long int)(l / c) * (long long int)(w / c) * (long long int)(h / c);
        if (temp < n)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << a;
}