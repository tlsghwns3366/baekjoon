#include <iostream>
#include <algorithm>
using namespace std;
int f(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    long long int n;
    cin >> n;
    int nn[6];
    long long int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> nn[i];
    }
    if (n == 1)
    {
        sort(nn, nn + 6);
        for (int i = 0; i < 5; i++)
        {
            ans += nn[i];
        }
    }
    else
    {
        long long int mint[3];
        mint[0] = f(nn[0], nn[5]);
        mint[1] = f(nn[1], nn[4]);
        mint[2] = f(nn[2], nn[3]);
        sort(mint, mint + 3);
        ans += mint[0] * ((n - 2) * (n - 2) + 4 * (n - 1) * (n - 2));
        ans += (mint[0] + mint[1]) * (8 * n - 12);
        ans += (mint[0] + mint[1] + mint[2]) * 4;
    }
    cout << ans;
}