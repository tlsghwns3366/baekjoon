#include <iostream>
using namespace std;
int n, k;
int ans = 0;
int b2[30] = {0,};
void f(int a)
{
    b2[a]++;
    if (b2[a] == 2)
    {
        f(a + 1);
        b2[a] = 0;
    }
}
int main()
{
    cin >> n >> k;
    b2[0] = n;
    for (int i = 0; i < 30; i++)
    {
        b2[i + 1] = b2[i] / 2;
        if (b2[i] % 2 == 0)
            b2[i] = 0;
        else
            b2[i] = 1;
    }

    while (true)
    {
        int temp = 0;
        for (int i = 0; i < 30; i++)
        {
            temp += b2[i];
        }
        if (temp <= k)
            break;
        ans++;
        f(0);
    }
    cout << ans;
}