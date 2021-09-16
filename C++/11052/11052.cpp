#include <iostream>
using namespace std;
int maxt(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int pn[n];
    fill(pn, pn + n, 0);
    pn[0] = p[0];
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= i; j++)
        {
            temp = maxt(temp, pn[i - j] + pn[j - 1]);
        }
        pn[i] = maxt(temp, p[i]);
    }
    cout << pn[n - 1];
}