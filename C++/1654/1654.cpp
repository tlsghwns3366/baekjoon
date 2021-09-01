#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int k, n;
    cin >> k >> n;
    int *kk = new int[k]{0};
    for (int i = 0; i < k; i++)
    {
        cin >> kk[i];
    }
    int count = 0;
    sort(kk, kk + k);

    long long a = kk[k - 1];
    long long b = 1;
    while (true)
    {
        long long temp = (a + b) / 2;
        count = 0;
        for (int i = 0; i < k; i++)
        {
            count += kk[i] / temp;
        }
        if (count < n)
        {
            a = temp - 1;
        }
        else if (count >= n)
        {
            b = temp + 1;
        }
        if (a == temp)
        {
            cout << a;
            break;
        }
    }
}