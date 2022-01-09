#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nt[i];
    }
    sort(nt, nt + n);
    long long int a = 0;
    long long int b = LONG_LONG_MAX;
    long long int ans = LONG_LONG_MAX;
    while (a < b)
    {
        long long int c = (a + b) / 2;
        long long int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += c / nt[i];
            if (temp >= m)
            {
                break;
            }
        }
        if (temp >= m)
        {
            b = c;
        }
        else
        {
            a = c + 1;
        }
    }
    cout << b;
}
