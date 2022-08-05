#include <iostream>
using namespace std;
int n;
string s;
int ans = -987654321;
int v(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
}
void f(int a, int b)
{
    if (a > n - 1)
    {
        ans = ans < b ? b : ans;
        return;
    }
    char op = a == 0 ? '+' : s[a - 1];
    if (a + 2 < n)
    {
        int temp = v(s[a] - '0', s[a + 2] - '0', s[a + 1]);
        f(a + 4, v(b, temp, op));
    }
    f(a + 2, v(b, s[a] - '0', op));
}
int main()
{
    cin >> n;
    cin >> s;
    f(0, 0);
    cout << ans;
}