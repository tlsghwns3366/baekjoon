#include <iostream>
#include <cmath>
using namespace std;

int x;
void f(int n, int a, int b, int c)
{
    if (n == 1)
        cout << a << " " << c << "\n";
    else
    {
        f(n - 1, a, c, b);
        cout << a << " " << c << "\n";
        f(n - 1, b, a, c);
    }
}
int main()
{
    cin >> x;
    string temp = to_string(pow(2, x));
    string ans = "";
    for (int i = 0; i < temp.length() - 1; i++)
    {
        if (temp[i] == '.')
            break;
        ans += temp[i];
    }
    ans[ans.length() - 1]--;
    cout << ans << "\n";
    if (x <= 20)
        f(x, 1, 2, 3);
}