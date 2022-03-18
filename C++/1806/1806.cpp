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
    int b = 1;
    int sum = nn[a];
    int count = 1;
    int ans = 100000001;
    while (b != n + 1)
    {
        if (sum >= s)
        {
            if (ans > count)
                ans = count;
            sum -= nn[a];
            count--;
            a++;
        }
        else
        {
            sum += nn[b];
            count++;
            b++;
        }
    }

    if (ans == 100000001)
        cout << 0;
    else
        cout << ans;
}