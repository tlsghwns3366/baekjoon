#include <iostream>
using namespace std;
int rev(string a)
{
    int ans = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        ans += a[i] - '0';
        if (i != 0)
            ans *= 10;
    }
    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << rev(to_string((rev(x) + rev(y))));
}