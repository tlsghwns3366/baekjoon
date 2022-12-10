#include <iostream>
using namespace std;
int b[4];
bool l[2001];
void f(int a, int c)
{
    if (a == 0)
    {
        l[b[0] * 1 + b[1] * 5 + b[2] * 10 + b[3] * 50] = true;
        return;
    }
    for (int i = c; i < 4; i++)
    {
        b[i]++;
        f(a - 1, i);
        b[i]--;
    }
}
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    f(n, 0);
    for (int i = 1; i < 2001; i++)
    {
        if (l[i])
            ans++;
    }
    cout << ans;
}