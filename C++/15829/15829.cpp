#include <iostream>
using namespace std;
int r = 31;
int m = 1234567891;
long long int f(int a)
{
    if (a == 0)
        return 1;
    return (f(a - 1) * r) % m;
}
int main()
{
    int L;
    string s;
    cin >> L >> s;
    long long int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ans += ((s[i] - 'a' + 1) * f(i)) % m;
        ans %= m;
    }
    cout << ans;
}