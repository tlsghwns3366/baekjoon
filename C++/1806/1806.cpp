#include <iostream>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int a = 0;
    int b = 0;
    int sum = 0;
    int ans = 100000001;
    while (a <= b)
    {
        if (b == n)
            break;
        if (sum >= s)
        {
            if (ans > b - a)
                ans = b - a;
            sum -= nn[a];
            a++;
        }
        else
        {
            sum += nn[b];
            b++;
        }
    }

    if (ans == 100000001)
        cout << 0;
    else
        cout << ans;
}