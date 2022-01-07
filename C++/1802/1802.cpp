#include <iostream>
using namespace std;
string s;
string ans;

void f(int a, int b)
{
    if (b <= a)
        return;
    int x = a;
    int y = b;
    while (x < y)
    {
        if (s[x] == s[y])
        {
            ans = "NO";
            return;
        }
        x++;
        y--;
    }
    f(a, y - 1);
}
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        ans = "YES";
        cin >> s;
        if (s.length() % 2 == 0)
        {
            ans == "NO";
            continue;
        }
        f(0, s.length() - 1);
        cout << ans << "\n";
    }
}