#include <iostream>
#include <string>
using namespace std;
int cp[10];
int n;
int p = 1;
int ans = -1;
string s = "";
void f(int a)
{
    if (a == 10)
    {
        for (int i = 9; i >= 11 - p; i--)
        {
            if (cp[i - 1] <= cp[i])
                return;
        }
        ans++;
        if (ans == n)
        {
            for (int i = 10 - p; i < 10; i++)
            {
                s += to_string(cp[i]);
            }
            return;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        cp[a] = i;
        if (cp[a - 1] != 0 && cp[a - 1] <= cp[a])
            return;
        f(a + 1);
        if (i == 9 && 10 - a >= p)
            p++;
    }
}
int main()
{
    cin >> n;
    if (n < 10)
        cout << n;
    else
    {
        f(0);
        if (s == "")
            cout << -1;
        else
            cout << s;
    }
}