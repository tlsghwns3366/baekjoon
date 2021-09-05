#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long a = n * n;
    long long b = 1;
    long long m = n * n;
    while (a >= b)
    {
        long long c = (a + b) / 2;
        long long count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c / i <= n)
                count += c / i;
            else
                count += n;
        }
        if (count >= k)
        {
            a = c - 1;
            m = c;
        }
        else if (count < k)
            b = c + 1;
    }
    cout << m;
}