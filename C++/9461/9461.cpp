#include <iostream>
using namespace std;
long long pado(long long *pn, int n)
{
    if (n < 5 || pn[n] != 0)
        return pn[n];
    else if (pn[n] == 0)
    {
        return pn[n] = pado(pn, n - 1) + pado(pn, n - 5);
    }
}
int main()
{
    int t;
    cin >> t;
    long long *pn = new long long[101]{0};

    pn[0] = 1;
    pn[1] = 1;
    pn[2] = 1;
    pn[3] = 2;
    pn[4] = 2;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << pado(pn, n - 1) << "\n";
    }
}